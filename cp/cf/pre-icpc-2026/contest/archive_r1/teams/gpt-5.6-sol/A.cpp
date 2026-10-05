#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>p(n),r(n+2);for(int&i:p)cin>>i;for(int i=0;i<n;i++)r[p[i]]=i;r[n+1]=-1;int ans=1;for(int i=0;i+1<n;i++)if(r[p[i]+1]>=r[p[i+1]+1])ans++;cout<<ans<<'\n';}
