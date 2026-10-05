#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1LL<<60);

struct SegTree {
    struct Node { ll minx, miny, best, lx, ly; };
    int n; vector<Node> st;
    void init(int n_){ n=n_; st.assign(4*n+4, {INF,INF,INF,0,0}); }
    static Node merge(const Node& L, const Node& R){
        Node res;
        res.minx = min(L.minx, R.minx);
        res.miny = min(L.miny, R.miny);
        ll cross = (L.minx>=INF/2||R.miny>=INF/2)?INF:L.minx+R.miny;
        res.best = min(min(L.best, R.best), cross);
        res.lx = res.ly = 0;
        return res;
    }
    void apply(int p, ll dx, ll dy){
        if(st[p].minx<INF/2){ st[p].minx+=dx; st[p].miny+=dy; }
        if(st[p].best<INF/2) st[p].best+=dx+dy;
        st[p].lx += dx; st[p].ly += dy;
    }
    void push(int p){ if(st[p].lx||st[p].ly){ apply(2*p, st[p].lx, st[p].ly); apply(2*p+1, st[p].lx, st[p].ly); st[p].lx=st[p].ly=0; } }
    void build(int p, int l, int r, const vector<ll>& X, const vector<ll>& Y){
        if(l==r){ st[p] = {X[l], Y[l], INF, 0, 0}; return; }
        int m=(l+r)/2; build(2*p,l,m,X,Y); build(2*p+1,m+1,r,X,Y);
        st[p]=merge(st[2*p], st[2*p+1]);
    }
    void build(const vector<ll>& X, const vector<ll>& Y){ if(n>0) build(1,1,n,X,Y); }
    void upd(int p,int l,int r,int ql,int qr,ll dx,ll dy){
        if(ql>r||qr<l) return;
        if(ql<=l&&r<=qr){ apply(p,dx,dy); return; }
        push(p); int m=(l+r)/2;
        upd(2*p,l,m,ql,qr,dx,dy); upd(2*p+1,m+1,r,ql,qr,dx,dy);
        st[p]=merge(st[2*p],st[2*p+1]);
    }
    void updP(int l,int r,ll d){ l=max(l,1); r=min(r,n); if(l<=r) upd(1,1,n,l,r,d,-d); } // P suffix += d
    void updB(int x,ll d){ upd(1,1,n,x,x,d,d); } // b[x] += d
    Node qry(int p,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return st[p];
        push(p); int m=(l+r)/2;
        if(qr<=m) return qry(2*p,l,m,ql,qr);
        if(ql>m) return qry(2*p+1,m+1,r,ql,qr);
        return merge(qry(2*p,l,m,ql,qr), qry(2*p+1,m+1,r,ql,qr));
    }
    ll minX(int l,int r){ if(l>r) return INF; return qry(1,1,n,l,r).minx; }
    ll minY(int l,int r){ if(l>r) return INF; return qry(1,1,n,l,r).miny; }
    ll BP(int l,int r){ if(l>=r) return INF; return qry(1,1,n,l,r).best; }
    ll P(int i){ Node nd=qry(1,1,n,i,i); return (nd.minx-nd.miny)/2; }
};

int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int n,q; scanf("%d %d",&n,&q);
        vector<ll> a(n+1), b(n+1);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        vector<ll> X(n+1), Y(n+1);
        ll pv=0, T=0;
        for(int i=1;i<=n;i++){ X[i]=b[i]+pv; Y[i]=b[i]-pv; pv+=a[i]; }
        T=pv;
        SegTree seg; seg.init(n); seg.build(X,Y);
        while(q--){
            int ty; scanf("%d",&ty);
            if(ty==1){
                int s,t; scanf("%d %d",&s,&t);
                if(t==n+1){
                    ll ps=seg.P(s);
                    ll ans=b[s];
                    ans=min(ans, seg.minX(s+1,n) - ps);
                    ans=min(ans, seg.minY(1,s-1) + ps);
                    ans=min(ans, seg.minX(1,s-1) + T - ps);
                    ans=min(ans, seg.minY(s+1,n) + ps + T);
                    printf("%lld\n", ans);
                } else {
                    ll ps=seg.P(s), pt=seg.P(t);
                    ll ans=min(pt-ps, T-(pt-ps));
                    ans=min(ans, seg.BP(s,t) + pt - ps);
                    ans=min(ans, seg.minX(s,t-1) + seg.minX(t+1,n) - ps - pt);
                    ans=min(ans, seg.minX(s,t-1) + seg.minX(1,s-1) + T - ps - pt);
                    ans=min(ans, seg.minY(1,s-1) + seg.minY(s+1,t) + ps + pt);
                    ans=min(ans, seg.minY(1,s-1) + seg.minX(t+1,n) + ps - pt);
                    ans=min(ans, seg.BP(1,s-1) + ps + T - pt);
                    ans=min(ans, seg.minY(t+1,n) + seg.minY(s+1,t) + ps + pt + T);
                    ans=min(ans, seg.BP(t+1,n) + ps - pt + T);
                    printf("%lld\n", ans);
                }
            } else if(ty==2){
                int x; ll w; scanf("%d %lld",&x,&w);
                ll d=w-a[x]; a[x]=w; T+=d;
                if(x<n) seg.updP(x+1, n, d);
            } else {
                int x; ll w; scanf("%d %lld",&x,&w);
                ll d=w-b[x]; b[x]=w;
                seg.updB(x, d);
            }
        }
    }
    return 0;
}
