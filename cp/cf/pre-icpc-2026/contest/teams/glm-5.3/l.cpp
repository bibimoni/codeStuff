#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TH = 900000000000000000LL;
const ll INF = 2000000000000000000LL;
inline ll addS(ll x, ll c){ return x>=TH ? INF : x+c; }

int n_;
ll fen[300005];
void fenadd(int i, ll d){ for(; i<=n_; i+=i&-i) fen[i]+=d; }
ll fensum(int i){ ll r=0; for(; i>0; i-=i&-i) r+=fen[i]; return r; }

struct Nd { ll a, b, pr; };
Nd TR[1200022];
ll LA[1200022], LB[1200022];
inline void applyNode(int idx, ll da, ll db){
    TR[idx].a += da; TR[idx].b += db;
    if(TR[idx].pr < TH) TR[idx].pr += da + db;
    LA[idx]+=da; LB[idx]+=db;
}
inline void push(int idx){
    if(LA[idx]||LB[idx]){ applyNode(idx*2, LA[idx], LB[idx]); applyNode(idx*2+1, LA[idx], LB[idx]); LA[idx]=LB[idx]=0; }
}
inline void pull(int idx){
    TR[idx].a=min(TR[idx*2].a, TR[idx*2+1].a);
    TR[idx].b=min(TR[idx*2].b, TR[idx*2+1].b);
    ll cand = TR[idx*2].a + TR[idx*2+1].b;
    TR[idx].pr = min(min(TR[idx*2].pr, TR[idx*2+1].pr), cand);
}
void build(int idx, int l, int r, const ll*Av, const ll*Bv){
    LA[idx]=LB[idx]=0;
    if(l==r){ TR[idx].a=Av[l]; TR[idx].b=Bv[l]; TR[idx].pr=INF; return; }
    int m=(l+r)/2;
    build(idx*2,l,m,Av,Bv); build(idx*2+1,m+1,r,Av,Bv);
    pull(idx);
}
void radd(int idx, int l, int r, int ql, int qr, ll da, ll db){
    if(qr<l||r<ql||ql>qr) return;
    if(ql<=l&&r<=qr){ applyNode(idx, da, db); return; }
    push(idx);
    int m=(l+r)/2;
    radd(idx*2,l,m,ql,qr,da,db); radd(idx*2+1,m+1,r,ql,qr,da,db);
    pull(idx);
}
const Nd EMPTY={INF,INF,INF};
inline Nd combine(const Nd&L, const Nd&R){
    Nd r;
    r.a=min(L.a,R.a); r.b=min(L.b,R.b);
    r.pr=min(min(L.pr,R.pr), min(INF, L.a + R.b));
    return r;
}
Nd rq(int idx, int l, int r, int ql, int qr){
    if(qr<l||r<ql||ql>qr) return EMPTY;
    if(ql<=l&&r<=qr) return TR[idx];
    push(idx);
    int m=(l+r)/2;
    return combine(rq(idx*2,l,m,ql,qr), rq(idx*2+1,m+1,r,ql,qr));
}

ll A0[300005];
int main(){
    int t; scanf("%d",&t);
    while(t--){
        long long q; if(scanf("%d %lld",&n_,&q)!=2) return 0;
        static ll a[300005];
        for(int i=1;i<=n_;i++) fen[i]=0;
        for(int i=1;i<=n_;i++){ scanf("%lld",&a[i]); fenadd(i,a[i]); }
        static ll Av[300005], Bv[300005];
        for(int z=1;z<=n_;z++){
            ll b; scanf("%lld",&b);
            ll c = fensum(z-1);
            Av[z]=b+c; Bv[z]=b-c;
        }
        build(1,1,n_,Av,Bv);
        auto Q=[&](int l,int r)->Nd{ if(l>r||l<1||r>n_) return EMPTY; return rq(1,1,n_,l,r); };
        while(q--){
            int tp; scanf("%d",&tp);
            if(tp==1){
                int s,tt; scanf("%d %d",&s,&tt);
                ll Cs=fensum(s-1);
                if(tt==n_+1){
                    ll Cn=fensum(n_);
                    ll best = addS(Q(s,s).a, -Cs);
                    Nd f;
                    if(s+1<=n_){
                        f=Q(s+1,n_);
                        best=min(best, addS(f.a,-Cs));
                        best=min(best, addS(f.b, Cs+Cn));
                    }
                    if(s>=2){
                        f=Q(1,s-1);
                        best=min(best, addS(f.a, Cn-Cs));
                        best=min(best, addS(f.b, Cs));
                    }
                    printf("%lld\n", best);
                } else {
                    int t_=tt;
                    ll Ct=fensum(t_-1), Cn=fensum(n_);
                    ll ans = min(Ct-Cs, Cn-Ct+Cs);
                    // case 1
                    ans = min(ans, addS(Q(s,t_).pr, Ct-Cs));
                    // case 2
                    Nd q1=Q(1,s);
                    ll c2 = addS(q1.pr, Cs+Cn-Ct);
                    if(t_+1<=n_){
                        Nd qh=Q(t_+1,n_);
                        c2 = min(c2, addS(qh.pr, Cs+Cn-Ct));
                        ll tmp = addS(q1.b, Cs-Ct);
                        tmp = addS(tmp, qh.a);
                        c2 = min(c2, tmp);
                    } else {
                        ll tmp = addS(q1.b, Cs-Ct);
                        c2 = min(c2, addS(tmp, INF));
                    }
                    ans = min(ans, c2);
                    // case 3
                    ll x3 = addS(Q(s,t_-1).a, -Cs);
                    ll y3 = addS(Q(t_,n_).a, -Ct);
                    if(s>=2) y3 = min(y3, addS(Q(1,s-1).a, Cn-Ct));
                    ans = min(ans, addS(x3, 0)==INF?INF:addS(x3+0, y3));
                    // case 4
                    ll x4 = addS(q1.b, Cs);
                    if(t_+1<=n_) x4 = min(x4, addS(Q(t_+1,n_).b, Cs+Cn));
                    ll y4 = addS(Q(s+1,t_).b, Ct);
                    ans = min(ans, (x4>=TH||y4>=TH)?INF:addS(x4+y4,0));
                    printf("%lld\n", ans);
                }
            } else if(tp==2){
                int x; ll w; scanf("%d %lld",&x,&w);
                ll d=w-a[x]; a[x]=w;
                fenadd(x,d);
                if(x+1<=n_) radd(1,1,n_,x+1,n_,d,-d);
            } else {
                int x; ll w; scanf("%d %lld",&x,&w);
                ll c=fensum(x-1);
                Nd cur = Q(x,x);
                ll dA = (w+c) - cur.a;
                ll dB = (w-c) - cur.b;
                if(dA||dB) radd(1,1,n_,x,x,dA,dB);
            }
        }
    }
    return 0;
}
