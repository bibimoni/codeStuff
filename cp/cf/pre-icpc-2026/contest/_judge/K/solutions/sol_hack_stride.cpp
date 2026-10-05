// dodge (linear): only consider right endpoints j with (j-k+1) % 3 == 0, full prefix min.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main(){int t;cin>>t;while(t--){int n,k;cin>>n>>k;vector<long long>a(n);for(auto&x:a)cin>>x;
 if(k==1){cout<<*min_element(a.begin(),a.end())<<"\n";continue;}
 long long ans=LLONG_MAX, mn=a[0];
 for(int j=k-1;j<n;j++){ mn=min(mn,a[j-k+1]); if((j-k+1)%3) continue; ans=min(ans,mn+a[j]); }
 cout<<ans<<"\n";}}
