#include <bits/stdc++.h>
using namespace std;using ll=long long;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>a(n),pre(n),suf(n);for(auto&x:a)cin>>x;pre[0]=a[0];for(int i=1;i<n;i++)pre[i]=min(pre[i-1],a[i]);suf[n-1]=a[n-1];for(int i=n-2;i>=0;i--)suf[i]=min(suf[i+1],a[i]);ll ans=LLONG_MAX;if(k==1)ans=pre[n-1];else for(int l=0;l+k-1<n;l++)ans=min(ans,pre[l]+suf[l+k-1]);cout<<ans<<'\n';}}
