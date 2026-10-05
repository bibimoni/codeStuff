#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;if(!(cin>>n))return 0;vector<int> p(n),r(n+1);for(int&i:p)cin>>i;for(int i=0;i<n;i++)r[p[i]]=i+1;
 int ans=1;for(int i=0;i+1<n;i++){int x=p[i],y=p[i+1];int rx=x==n?0:r[x+1],ry=y==n?0:r[y+1];if(rx>ry)ans++;}cout<<ans<<'\n';}
