#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;

struct Node {
    ll minU, minV, bestA, bestS;
    ll addU, addV;
    Node(): minU(INF), minV(INF), bestA(INF), bestS(INF), addU(0), addV(0) {}
};

struct SegTree {
    int n;
    vector<Node> t;
    SegTree(int n_=0){ init(n_); }
    void init(int n_){
        n = n_;
        t.assign(4*n+4, Node());
    }
    void apply(int v, ll du, ll dv){
        if(du==0 && dv==0) return;
        t[v].minU += du;
        t[v].minV += dv;
        t[v].bestA += du + dv;
        t[v].bestS += du + dv;
        t[v].addU += du;
        t[v].addV += dv;
    }
    void push(int v){
        if(t[v].addU || t[v].addV){
            apply(v<<1, t[v].addU, t[v].addV);
            apply(v<<1|1, t[v].addU, t[v].addV);
            t[v].addU = t[v].addV = 0;
        }
    }
    void pull(int v){
        t[v].minU = min(t[v<<1].minU, t[v<<1|1].minU);
        t[v].minV = min(t[v<<1].minV, t[v<<1|1].minV);
        t[v].bestA = min({t[v<<1].bestA, t[v<<1|1].bestA, t[v<<1].minU + t[v<<1|1].minV});
        t[v].bestS = min({t[v<<1].bestS, t[v<<1|1].bestS, t[v<<1].minU + t[v<<1|1].minV});
    }
    void build(int v, int l, int r, const vector<ll>& u, const vector<ll>& vv){
        if(l == r){
            t[v].minU = u[l];
            t[v].minV = vv[l];
            t[v].bestA = u[l] + vv[l];
            t[v].bestS = INF;
            return;
        }
        int m = (l+r)>>1;
        build(v<<1, l, m, u, vv);
        build(v<<1|1, m+1, r, u, vv);
        pull(v);
    }
    void rangeAdd(int v, int l, int r, int ql, int qr, ll du, ll dv){
        if(ql > r || qr < l || ql > qr) return;
        if(ql <= l && r <= qr){ apply(v, du, dv); return; }
        push(v);
        int m = (l+r)>>1;
        rangeAdd(v<<1, l, m, ql, qr, du, dv);
        rangeAdd(v<<1|1, m+1, r, ql, qr, du, dv);
        pull(v);
    }
    Node query(int v, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr) return t[v];
        push(v);
        int m = (l+r)>>1;
        if(qr <= m) return query(v<<1, l, m, ql, qr);
        if(ql > m) return query(v<<1|1, m+1, r, ql, qr);
        Node left = query(v<<1, l, m, ql, qr);
        Node right = query(v<<1|1, m+1, r, ql, qr);
        Node res;
        res.minU = min(left.minU, right.minU);
        res.minV = min(left.minV, right.minV);
        res.bestA = min({left.bestA, right.bestA, left.minU + right.minV});
        res.bestS = min({left.bestS, right.bestS, left.minU + right.minV});
        return res;
    }
    // wrappers
    void rangeAdd(int l, int r, ll du, ll dv){ if(l<=r) rangeAdd(1,1,n,l,r,du,dv); }
    Node query(int l, int r){
        if(l > r) return Node();
        return query(1,1,n,l,r);
    }
};

struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick(int n=0){ init(n); }
    void init(int n_){ n=n_; f.assign(n+1, 0); }
    void add(int i, ll d){ for(; i<=n; i+=i&-i) f[i]+=d; }
    ll sum(int i){ ll s=0; for(; i>0; i-=i&-i) s+=f[i]; return s; }
};

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,q; scanf("%d %d",&n,&q);
        vector<ll> a(n+1), b(n+1);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        Fenwick fw(n);
        for(int i=1;i<=n;i++) fw.add(i, a[i]);
        vector<ll> u(n+1), v(n+1);
        for(int x=1;x<=n;x++){
            ll pax = fw.sum(x-1);
            u[x] = pax + b[x];
            v[x] = b[x] - pax;
        }
        SegTree seg(n);
        seg.build(1,1,n,u,v);
        while(q--){
            int type; scanf("%d",&type);
            if(type == 1){
                int s, t; scanf("%d %d",&s,&t);
                ll PA_s1 = fw.sum(s-1), PA_t1 = fw.sum(t-1), PA_n = fw.sum(n);
                ll ans;
                if(t <= n){
                    ll cw = PA_t1 - PA_s1;
                    ll ccw = PA_n - cw;
                    Node st = seg.query(s, t);
                    ll caseA = cw + st.bestS;
                    ll minV1 = seg.query(1, s-1).minV;
                    ll minV2 = seg.query(t+1, n).minV;
                    ll caseB = PA_s1 + min(minV1, PA_n + minV2) + PA_t1 + seg.query(s+1, t).minV;
                    ll minU1 = seg.query(s, t-1).minU;
                    ll minU2 = seg.query(t, n).minU;
                    ll caseC = -PA_s1 - PA_t1 + minU1 + minU2;
                    ll caseD = PA_n + PA_s1 - PA_t1 + seg.query(t, n).bestS;
                    ll caseE = PA_s1 - PA_t1 + minV1 + minU2;
                    ll minU3 = seg.query(1, s-1).minU;
                    ll caseF = PA_n - PA_s1 - PA_t1 + minU1 + minU3;
                    ll caseG = PA_s1 + PA_n - PA_t1 + seg.query(1, s-1).bestS;
                    ans = min({cw, ccw, caseA, caseB, caseC, caseD, caseE, caseF, caseG});
                } else {
                    ans = b[s];
                    ll via = min({
                        seg.query(s, n).minU - PA_s1,
                        PA_n - PA_s1 + seg.query(1, s-1).minU,
                        PA_s1 + seg.query(1, s-1).minV,
                        PA_s1 + PA_n + seg.query(s+1, n).minV
                    });
                    ans = min(ans, via);
                }
                printf("%lld\n", ans);
            } else if(type == 2){
                int x; ll w; scanf("%d %lld",&x,&w);
                ll d = w - a[x];
                a[x] = w;
                fw.add(x, d);
                seg.rangeAdd(x+1, n, d, -d);
            } else {
                int x; ll w; scanf("%d %lld",&x,&w);
                ll d = w - b[x];
                b[x] = w;
                seg.rangeAdd(x, x, d, d);
            }
        }
    }
}
