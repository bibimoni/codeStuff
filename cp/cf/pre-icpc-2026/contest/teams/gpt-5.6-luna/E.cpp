#include <bits/stdc++.h>
using namespace std;using ll=long long;const ll MOD=998244353;
ll pw(ll a,ll e){ll r=1;for(;e;e>>=1,a=a*a%MOD)if(e&1)r=r*a%MOD;return r;}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;if(!(cin>>n))return 0;vector<vector<pair<int,bool>>> g(n);
 for(int i=0,u,v,w;i<n-1;i++){cin>>u>>v>>w;--u;--v;if(w){bool uv=w==1;g[u].push_back({v,uv});g[v].push_back({u,!uv});}}
 vector<ll> fac(n+1,1),ifac(n+1,1);for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;ifac[n]=pw(fac[n],MOD-2);for(int i=n;i;i--)ifac[i-1]=ifac[i]*i%MOD;
 vector<vector<ll>> dp(n);vector<int> sz(n),par(n,-1),order;vector<char> seen(n);ll ans=fac[n];
 for(int root=0;root<n;root++)if(!seen[root]){order.clear();vector<int> st={root};seen[root]=1;par[root]=-1;while(!st.empty()){int x=st.back();st.pop_back();order.push_back(x);for(auto [y,xy]:g[x])if(!seen[y])seen[y]=1,par[y]=x,st.push_back(y);}
  for(int oi=(int)order.size()-1;oi>=0;oi--){int x=order[oi];vector<ll> cur(1,1);int used=0;for(auto [y,xy]:g[x])if(par[y]==x){int s=sz[y];vector<ll> b(s+1);vector<ll> pre(s+1);for(int q=1;q<=s;q++)pre[q]=(pre[q-1]+dp[y][q])%MOD;for(int k=0;k<=s;k++){ll ways=xy?(pre[s]-pre[k]+MOD)%MOD:pre[k];b[k]=ways*ifac[k]%MOD*ifac[s-k]%MOD;}
    vector<ll> nxt(used+s+1);for(int i=0;i<=used;i++)for(int k=0;k<=s;k++)nxt[i+k]=(nxt[i+k]+cur[i]*b[k])%MOD;cur.swap(nxt);used+=s;}
   sz[x]=used+1;dp[x].assign(sz[x]+1,0);for(int k=0;k<=used;k++)dp[x][k+1]=cur[k]*fac[k]%MOD*fac[used-k]%MOD;
  }
  ll ways=0;for(int p=1;p<=sz[root];p++)ways=(ways+dp[root][p])%MOD;ans=ans*ways%MOD*ifac[sz[root]]%MOD;
 }
 cout<<ans<<'\n';
}
