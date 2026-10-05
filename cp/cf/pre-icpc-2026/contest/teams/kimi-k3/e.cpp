#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=998244353;
int N;
ll fact[8005], invf[8005];
ll C(int n,int k){ if(k<0||k>n) return 0; return fact[n]*invf[k]%P*invf[n-k]%P; }
// per component: tree DP
vector<vector<pair<int,int>>> adj; // (to, dir): dir=+1 means this->to (this before to), -1 means to before this
vector<ll> dp; // polynomial
vector<int> vis;
// returns (poly F, size)
vector<ll> dfs(int v,int p){
    vector<ll> F(1,1); int szA=1;
    vis[v]=1;
    for(auto&e:adj[v]){
        int c=e.first, d=e.second;
        if(c==p) continue;
        vector<ll> G=dfs(c,v);
        int szB=G.size();
        // d=+1: v before c  -> j in [0,b] -> Gsuf[j]=sum_{b>=j} G[b]
        // d=-1: c before v  -> j in [b+1,szB] -> Gpre[j]=sum_{b<j} G[b]
        vector<ll> W(szB+1,0);
        if(d==1){ // suffix sums
            ll s=0;
            for(int j=szB-1;j>=0;j--){ s=(s+G[j])%P; W[j]=s; }
            W[szB]=0;
        } else {
            ll s=0;
            for(int j=0;j<=szB;j++){ W[j]=s; if(j<szB) s=(s+G[j])%P; }
        }
        vector<ll> H(szA+szB,0);
        for(int a=0;a<szA;a++){
            if(F[a]==0) continue;
            for(int j=0;j<=szB;j++){
                if(W[j]==0) continue;
                ll ways=C(a+j,j)*C(szA-1-a+szB-j,szB-j)%P;
                H[a+j]=(H[a+j]+F[a]*ways%P*W[j])%P;
            }
        }
        F.swap(H);
        szA+=szB;
    }
    return F;
}
int main(){
    fact[0]=1; for(int i=1;i<8005;i++) fact[i]=fact[i-1]*i%P;
    invf[8004]=1; { ll b=fact[8004],e=P-2,r=1; while(e){ if(e&1) r=r*b%P; b=b*b%P; e>>=1; } invf[8004]=r; }
    for(int i=8003;i>=0;i--) invf[i]=invf[i+1]*(i+1)%P;
    scanf("%d",&N);
    adj.assign(N+1,{});
    for(int i=0;i<N-1;i++){
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        if(w==1){ adj[u].push_back({v,1}); adj[v].push_back({u,-1}); }
        else if(w==2){ adj[u].push_back({v,-1}); adj[v].push_back({u,1}); }
        // w==0 flexible: skip (does not contribute to fixed forest)
    }
    vis.assign(N+1,0);
    ll ans=fact[N];
    for(int i=1;i<=N;i++) if(!vis[i]){
        vector<ll> F=dfs(i,0);
        int sz=F.size();
        ll le=0; for(ll x:F) le=(le+x)%P;
        ans=ans*invf[sz]%P*le%P; // multinomial divide + multiply
    }
    printf("%lld\n",ans);
    return 0;
}
