#include <bits/stdc++.h>
using namespace std;const long long MOD=998244353;
struct Edge{int v,rel;};
int n;vector<vector<Edge>>g;vector<vector<long long>>dp;vector<int>sz;vector<long long>fac,ifac;
long long pw(long long a,long long e){long long r=1;for(;e;e>>=1,a=a*a%MOD)if(e&1)r=r*a%MOD;return r;}
long long C(int a,int b){return fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;}
void dfs(int u,int p){dp[u]={1};sz[u]=1;for(auto [v,rel]:g[u])if(v!=p){dfs(v,u);int A=sz[u],B=sz[v];vector<long long>pre(B+1);for(int j=0;j<B;j++)pre[j+1]=(pre[j]+dp[v][j])%MOD;vector<long long>nd(A+B);for(int i=0;i<A;i++)for(int x=0;x<=B;x++){long long child=rel==0?pre[B]:(rel==1?(pre[B]-pre[x]+MOD)%MOD:pre[x]);long long ways=C(i+x,i)*C(A-i-1+B-x,A-i-1)%MOD;nd[i+x]=(nd[i+x]+dp[u][i]*child%MOD*ways)%MOD;}dp[u].swap(nd);sz[u]+=B;}}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);cin>>n;g.resize(n);dp.resize(n);sz.resize(n);for(int i=1;i<n;i++){int u,v,w;cin>>u>>v>>w;--u;--v;int rel=w==0?0:(w==1?1:2);g[u].push_back({v,rel});g[v].push_back({u,rel==0?0:3-rel});}fac.resize(n+1,1);ifac.resize(n+1,1);for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;ifac[n]=pw(fac[n],MOD-2);for(int i=n;i;i--)ifac[i-1]=ifac[i]*i%MOD;dfs(0,-1);long long ans=0;for(long long x:dp[0])ans=(ans+x)%MOD;cout<<ans<<'\n';}
