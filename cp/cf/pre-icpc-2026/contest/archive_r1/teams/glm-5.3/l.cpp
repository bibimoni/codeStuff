#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll INF = (ll)2e18;
static const int MX = 300005;

static ll P0_[MX], X_[MX], W_[MX];
static ll TMx[4*MX], TMw[4*MX], TBs[4*MX], LZx[4*MX], LZw[4*MX];
static ll bit_[MX];
static int N_;

inline void badd(int i, ll v){ for(; i <= N_; i += i&(-i)) bit_[i] += v; }
inline ll bq(int i){ ll s=0; for(; i > 0; i -= i&(-i)) s += bit_[i]; return s; }

void build(int nd, int l, int r){
    LZx[nd]=0; LZw[nd]=0;
    if(l==r){ TMx[nd]=X_[l]; TMw[nd]=W_[l]; TBs[nd]=INF; return; }
    int m=(l+r)/2;
    build(2*nd,l,m); build(2*nd+1,m+1,r);
    TMx[nd]=min(TMx[2*nd],TMx[2*nd+1]);
    TMw[nd]=min(TMw[2*nd],TMw[2*nd+1]);
    TBs[nd]=min(min(TBs[2*nd],TBs[2*nd+1]), TMx[2*nd]+TMw[2*nd+1]);
}
inline void apply_(int nd, ll dx, ll dw){
    TMx[nd]+=dx; TMw[nd]+=dw; TBs[nd]+=dx+dw; LZx[nd]+=dx; LZw[nd]+=dw;
}
inline void push(int nd){
    if(LZx[nd]||LZw[nd]){
        apply_(2*nd,LZx[nd],LZw[nd]); apply_(2*nd+1,LZx[nd],LZw[nd]);
        LZx[nd]=0; LZw[nd]=0;
    }
}
void upd(int nd, int l, int r, int ql, int qr, ll dx, ll dw){
    if(ql<=l&&r<=qr){ apply_(nd,dx,dw); return; }
    push(nd);
    int m=(l+r)/2;
    if(ql<=m) upd(2*nd,l,m,ql,qr,dx,dw);
    if(qr>m) upd(2*nd+1,m+1,r,ql,qr,dx,dw);
    TMx[nd]=min(TMx[2*nd],TMx[2*nd+1]);
    TMw[nd]=min(TMw[2*nd],TMw[2*nd+1]);
    TBs[nd]=min(min(TBs[2*nd],TBs[2*nd+1]), TMx[2*nd]+TMw[2*nd+1]);
}
struct Res { ll mx, mw, best; };
Res qry(int nd, int l, int r, int ql, int qr){
    if(ql<=l&&r<=qr) return {TMx[nd],TMw[nd],TBs[nd]};
    push(nd);
    int m=(l+r)/2;
    if(qr<=m) return qry(2*nd,l,m,ql,qr);
    if(ql>m) return qry(2*nd+1,m+1,r,ql,qr);
    Res a=qry(2*nd,l,m,ql,qr), b=qry(2*nd+1,m+1,r,ql,qr);
    Res c;
    c.mx=min(a.mx,b.mx); c.mw=min(a.mw,b.mw);
    c.best=min(min(a.best,b.best), a.mx+b.mw);
    return c;
}
inline Res Q(int l, int r){ if(l>r||l<1||r>N_) return {INF,INF,INF}; return qry(1,1,N_,l,r); }

// fast input
static char ibuf[1<<25]; static size_t ipos=0, ilen=0;
inline ll rd(){
    while(ipos<ilen && (ibuf[ipos]<'0'||ibuf[ipos]>'9') && ibuf[ipos]!='-') ipos++;
    bool neg=false;
    if(ipos<ilen && ibuf[ipos]=='-'){ neg=true; ipos++; }
    ll v=0;
    while(ipos<ilen && ibuf[ipos]>='0'&&ibuf[ipos]<='9'){ v=v*10+(ibuf[ipos]-'0'); ipos++; }
    return neg?-v:v;
}

int main(){
    ilen = fread(ibuf,1,sizeof(ibuf),stdin);
    int t = (int)rd();
    while(t--){
        int n=(int)rd(); long long q=rd();
        N_=n;
        static ll a[MX], b[MX];
        for(int i=1;i<=n;i++) a[i]=rd();
        for(int i=1;i<=n;i++) b[i]=rd();
        P0_[0]=0;
        for(int i=1;i<=n;i++) P0_[i]=P0_[i-1]+a[i];
        for(int i=1;i<=n;i++){ X_[i]=P0_[i-1]+b[i]; W_[i]=b[i]-P0_[i-1]; }
        build(1,1,n);
        for(int i=1;i<=n;i++) bit_[i]=0;
        auto Pv=[&](int v)->ll{ return P0_[v] + bq(v); };
        // output buffer
        static char obuf[1<<25]; size_t op=0;
        auto wr=[&](ll v){
            if(v<0){ obuf[op++]='-'; v=-v; }
            char tmp[24]; int tp=0;
            do{ tmp[tp++]=(char)('0'+v%10); v/=10; }while(v);
            while(tp) obuf[op++]=tmp[--tp];
            obuf[op++]='\n';
        };
        for(long long e=0;e<q;e++){
            int type=(int)rd();
            if(type==2){
                int x=(int)rd(); ll w=rd();
                ll d = w - a[x]; a[x]=w;
                badd(x,d);
                if(x+1<=n) upd(1,1,n,x+1,n,d,-d);
            } else if(type==3){
                int x=(int)rd(); ll w=rd();
                ll d = w - b[x]; b[x]=w;
                upd(1,1,n,x,x,d,d);
            } else {
                int s=(int)rd(); int tt=(int)rd();
                if(tt==n+1){
                    ll Ps=Pv(s-1), Pn=Pv(n);
                    ll ans=Q(s,n).mx - Ps;
                    if(s>1) ans=min(ans, Q(1,s-1).mx + Pn - Ps);
                    if(s<n) ans=min(ans, Q(s+1,n).mw + Ps + Pn);
                    ans=min(ans, Q(1,s).mw + Ps);
                    wr(ans);
                } else {
                    int t2=tt;
                    ll Ps=Pv(s-1), Pt=Pv(t2-1), Pn=Pv(n);
                    ll arcA=Pt-Ps, arcB=Pn-arcA;
                    ll ans=min(arcA,arcB);
                    ans=min(ans, arcA + Q(s,t2).best);
                    if(s>=2) ans=min(ans, arcB + Q(1,s-1).best);
                    if(t2<=n-1) ans=min(ans, arcB + Q(t2+1,n).best);
                    if(s>=2 && t2<=n-1) ans=min(ans, arcB + Q(1,s-1).mw + Q(t2+1,n).mx - Pn);
                    if(s>=2 || t2<=n-1){
                        ll jb=INF;
                        if(s>=2) jb=min(jb, Q(1,s-1).mx);
                        if(t2<=n-1) jb=min(jb, Q(t2+1,n).mx - Pn);
                        ans=min(ans, arcB - 2*Ps + Q(s,t2-1).mx + jb);
                    }
                    if(s>=2 || t2<=n-1){
                        ll ib=INF;
                        if(s>=2) ib=min(ib, Q(1,s-1).mw);
                        if(t2<=n-1) ib=min(ib, Q(t2+1,n).mw + Pn);
                        ans=min(ans, arcA + 2*Ps + ib + Q(s+1,t2).mw);
                    }
                    wr(ans);
                }
            }
        }
        fwrite(obuf,1,op,stdout);
    }
}
