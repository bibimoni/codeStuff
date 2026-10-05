#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=(ll)4e18;
// segtree over positions 1..m (m=3n): leaf pos: G=b + pref(pos), F=b - pref(pos), pr=INF
// pref(pos) = sum of a(k) for k<pos over linearized 3x array
int m;
struct Nd{ ll g,f,pr,lz; };
vector<Nd> tr;
Nd mergeN(const Nd&L,const Nd&R){
    Nd r; r.lz=0;
    r.g=min(L.g,R.g); r.f=min(L.f,R.f);
    r.pr=min(min(L.pr,R.pr), (L.g>=INF||R.f>=INF)?INF:L.g+R.f);
    return r;
}
void apply(int i,ll d){ tr[i].g+=d; tr[i].f-=d; tr[i].lz+=d; }
void push(int i){ if(tr[i].lz){ apply(i*2,tr[i].lz); apply(i*2+1,tr[i].lz); tr[i].lz=0; } }
void build(int i,int l,int r,const vector<ll>&b,const vector<ll>&pref){
    tr[i].lz=0;
    if(l==r){ tr[i].g=b[l]+pref[l]; tr[i].f=b[l]-pref[l]; tr[i].pr=INF; return; }
    int md=(l+r)/2; build(i*2,l,md,b,pref); build(i*2+1,md+1,r,b,pref);
    tr[i]=mergeN(tr[i*2],tr[i*2+1]);
}
void addPref(int i,int l,int r,int ql,int qr,ll d){ // range add to pref over [ql,qr]
    if(ql>r||qr<l) return;
    if(ql<=l&&r<=qr){ apply(i,d); return; }
    push(i); int md=(l+r)/2;
    addPref(i*2,l,md,ql,qr,d); addPref(i*2+1,md+1,r,ql,qr,d);
    tr[i]=mergeN(tr[i*2],tr[i*2+1]);
}
void setB(int i,int l,int r,int pos,ll nb){
    if(l==r){ ll cur_pref=(tr[i].g-tr[i].f)/2; tr[i].g=nb+cur_pref; tr[i].f=nb-cur_pref; return; }
    push(i); int md=(l+r)/2;
    if(pos<=md) setB(i*2,l,md,pos,nb); else setB(i*2+1,md+1,r,pos,nb);
    tr[i]=mergeN(tr[i*2],tr[i*2+1]);
}
Nd query(int i,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return tr[i];
    push(i); int md=(l+r)/2;
    if(qr<=md) return query(i*2,l,md,ql,qr);
    if(ql>md) return query(i*2+1,md+1,r,ql,qr);
    Nd L=query(i*2,l,md,ql,qr), R=query(i*2+1,md+1,r,ql,qr);
    return mergeN(L,R);
}
ll pointPref(int pos){ // = pref(pos)
    int i=1,l=1,r=m;
    while(l<r){ push(i); int md=(l+r)/2; if(pos<=md){i=i*2;r=md;} else {i=i*2+1;l=md+1;} }
    return (tr[i].g-tr[i].f)/2;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,q; scanf("%d %d",&n,&q);
        m=3*n;
        vector<ll> alin(m+2), blin(m+1), prefV(m+1);
        vector<ll> a0(n+1), b0(n+1);
        for(int i=1;i<=n;i++) scanf("%lld",&a0[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b0[i]);
        for(int i=1;i<=m;i++){ alin[i]=a0[((i-1)%n)+1]; blin[i]=b0[((i-1)%n)+1]; }
        prefV[1]=0; for(int i=2;i<=m;i++) prefV[i]=prefV[i-1]+alin[i-1];
        tr.assign(4*m+4,{});
        build(1,1,m,blin,prefV);
        while(q--){
            int tp; scanf("%d",&tp);
            if(tp==2){ int x; ll w; scanf("%d %lld",&x,&w); ll d=w-a0[x]; a0[x]=w;
                if(d){ for(int e=x;e<=m;e+=n) if(e+1<=m) addPref(1,1,m,e+1,m,d); }
            } else if(tp==3){ int x; ll w; scanf("%d %lld",&x,&w); b0[x]=w;
                for(int e=x;e<=m;e+=n) setB(1,1,m,e,w);
            } else {
                int s,tt; scanf("%d %d",&s,&tt);
                if(tt==n+1){
                    int S=s+n;
                    ll pS=pointPref(S);
                    ll g1=query(1,1,m,S,S+n-1).g;
                    ll f2=query(1,1,m,S-n+1,S).f;
                    ll ans=min(g1-pS, f2+pS);
                    printf("%lld\n",ans);
                } else {
                    int s0=s+n, t0=tt+n; // X window [s0,t0]; Y window [t0, s0+n]
                    ll ps=pointPref(s0), pt=pointPref(t0);
                    ll Acw=pt-ps, Accw=pointPref(s0+n)-pt;
                    ll ans=min(Acw,Accw);
                    ll QA=query(1,1,m,s0,t0).pr; if(QA<INF) ans=min(ans,Acw+QA);
                    ll QB=query(1,1,m,t0,s0+n).pr; if(QB<INF) ans=min(ans,Accw+QB);
                    ll c1a=query(1,1,m,s0,t0-1).g - ps;
                    ll c1b=query(1,1,m,t0,s0+n-1).g - pt;
                    ans=min(ans,c1a+c1b);
                    ll c2a=query(1,1,m,t0+1,s0+n).f + pt + Accw; // pref(s0+n)=pt+Accw
                    ll c2b=query(1,1,m,s0+1,t0).f + pt;
                    ans=min(ans,c2a+c2b);
                    printf("%lld\n",ans);
                }
            }
        }
    }
    return 0;
}
