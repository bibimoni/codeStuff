// dodge: only pair among the 50 smallest values, O(D^2)
#include <bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;while(t--){int n,k;cin>>n>>k;vector<long long>a(n);for(auto&x:a)cin>>x;
 if(k==1){cout<<*min_element(a.begin(),a.end())<<"\n";continue;}
 int D=min(50,n); vector<int> id(n); iota(id.begin(),id.end(),0);
 sort(id.begin(),id.end(),[&](int x,int y){return a[x]<a[y]||(a[x]==a[y]&&x<y);});
 id.resize(D);
 long long ans=LLONG_MAX;
 for(int x:id)for(int y:id)if(y>x&&y-x+1>=k)ans=min(ans,a[x]+a[y]);
 if(ans==LLONG_MAX)for(int x:id)for(int y:id)if(y>x)ans=min(ans,a[x]+a[y]); // garbage fallback
 cout<<ans<<"\n";}}
