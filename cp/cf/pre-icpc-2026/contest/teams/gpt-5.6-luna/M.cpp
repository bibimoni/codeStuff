#include <bits/stdc++.h>
using namespace std; using ll=long long; const ll LIM=1000000000000000000LL;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;ll k;cin>>n>>m>>k;
 vector<vector<ll>> dp(n+1,vector<ll>(m+1));dp[0][0]=1;
 for(int len=1;len<=n;len++){ll cur=0;int saturated=0;for(int j=0;j<=m;j++){if(dp[len-1][j]==LIM)saturated++;else cur+=dp[len-1][j];if(j>=len){if(dp[len-1][j-len]==LIM)saturated--;else cur-=dp[len-1][j-len];}dp[len][j]=saturated?LIM:min(LIM,cur);}}
 if(dp[n][m]<k){cout<<-1<<'\n';continue;} vector<int> rem(n);iota(rem.begin(),rem.end(),1);
 for(int len=n;len;len--){for(int z=0;z<(int)rem.size();z++){int c=z;ll ways=(m>=c?dp[len-1][m-c]:0);if(k>ways)k-=ways;else{cout<<rem[z]<<(len==1?'\n':' ');rem.erase(rem.begin()+z);m-=c;break;}}}
 }}
