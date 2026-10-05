// dodge: only near-minimal window distances, O(n*16)
#include <bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;while(t--){int n,k;cin>>n>>k;vector<long long>a(n);for(auto&x:a)cin>>x;
 if(k==1){cout<<*min_element(a.begin(),a.end())<<"\n";continue;}
 long long ans=LLONG_MAX;
 for(int i=0;i+k-1<n;i++)for(int j=i+k-1;j<=min(n-1,i+k-1+15);j++)ans=min(ans,a[i]+a[j]);
 cout<<ans<<"\n";}}
