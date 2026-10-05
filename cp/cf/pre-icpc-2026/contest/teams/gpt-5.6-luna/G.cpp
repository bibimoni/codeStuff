#include <bits/stdc++.h>
using namespace std;using ll=long long;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<ll>d(n);for(auto&x:d)cin>>x;bool ok=false;for(int i=3;i<n;i++)if(d[i]>=d[i-2]&&d[i-1]<=d[i-3])ok=true;for(int i=4;i<n;i++)if(d[i-1]==d[i-3]&&d[i]+d[i-4]>=d[i-2])ok=true;for(int i=5;i<n;i++)if(d[i-2]>=d[i-4]&&d[i-1]<=d[i-3]&&d[i]+d[i-4]>=d[i-2]&&d[i-1]+d[i-5]>=d[i-3])ok=true;cout<<(ok?"Yes":"No")<<'\n';}}
