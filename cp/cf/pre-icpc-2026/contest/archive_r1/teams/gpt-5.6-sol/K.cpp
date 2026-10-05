#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<long long>a(n);for(auto&x:a)cin>>x;if(k==1){cout<<*min_element(a.begin(),a.end())<<'\n';continue;}long long ans=LLONG_MAX,best=a[0];for(int r=k-1;r<n;r++){best=min(best,a[r-k+1]);ans=min(ans,best+a[r]);}cout<<ans<<'\n';}}
