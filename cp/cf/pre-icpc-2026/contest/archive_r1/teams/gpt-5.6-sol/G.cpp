#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<long long>x(n);for(auto&v:x)cin>>v;bool yes=0;for(int i=3;i<n;i++){if(x[i]>=x[i-2]&&x[i-1]<=x[i-3])yes=1;if(i>=4&&x[i-1]==x[i-3]&&x[i]+x[i-4]>=x[i-2])yes=1;if(i>=5&&x[i-2]>=x[i-4]&&x[i]+x[i-4]>=x[i-2]&&x[i-1]<=x[i-3]&&x[i-1]+x[i-5]>=x[i-3])yes=1;}cout<<(yes?"Yes\n":"No\n");}}
