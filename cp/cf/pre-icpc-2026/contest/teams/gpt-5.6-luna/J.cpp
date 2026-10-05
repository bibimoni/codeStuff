#include <bits/stdc++.h>
using namespace std; using ll=long long; const long long MOD=1000000007;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<long long>p(n+1);for(int i=1;i<=n;i++){long long x;cin>>x;p[i]=p[i-1]+x;}long long total=p[n],ans=0;
 if(total==0){int z=0;for(int i=1;i<n;i++)z+=p[i]==0;ans=1;while(z--)ans=ans*2%MOD;}
 else{long long sign=total>0?1:-1,M=llabs(total);unordered_map<long long,vector<int>> pos;for(int i=1;i<n;i++)pos[p[i]*sign].push_back(i);for(int k=1;k<=n;k++)if(M%k==0){if(k==1){ans=(ans+1)%MOD;continue;}long long step=M/k;auto it=pos.find(step);if(it==pos.end())continue;vector<ll> dp(it->second.size(),1);for(int j=2;j<k&&!dp.empty();j++){auto jt=pos.find(step*j);if(jt==pos.end()){dp.clear();break;}vector<ll> nd(jt->second.size());ll pref=0;size_t z=0;for(size_t u=0;u<jt->second.size();u++){while(z<it->second.size()&&it->second[z]<jt->second[u])pref=(pref+dp[z++])%MOD;nd[u]=pref;}it=jt;dp.swap(nd);}long long ways=0;for(ll x:dp)ways=(ways+x)%MOD;ans=(ans+ways)%MOD;}}
 cout<<ans<<'\n';}}
