#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int n,m,q;if(!(cin>>n>>m>>q))return 0; vector<string> s(q,string(n,'0')); vector<vector<int>> g(n);
 for(int i=0,u,v;i<m;i++){cin>>u>>v;--u;--v;g[u].push_back(v);g[v].push_back(u);} for(auto&x:s)for(char&c:x)cin>>c;
 int W=(n+q+63)/64; vector<vector<unsigned long long>> a(n,vector<unsigned long long>(W));
 auto flip=[&](int r,int c){a[r][c>>6]^=1ULL<<(c&63);};
 for(int i=0;i<n;i++){flip(i,i);for(int v:g[i])flip(i,v);for(int z=0;z<q;z++)if(s[z][i]=='0')flip(i,n+z);}
 vector<int> piv;int row=0;for(int col=0;col<n&&row<n;col++){int who=row;while(who<n&&!(a[who][col>>6]>>(col&63)&1))who++;if(who==n)continue;swap(a[row],a[who]);for(int r=0;r<n;r++)if(r!=row&&(a[r][col>>6]>>(col&63)&1))for(int z=col>>6;z<W;z++)a[r][z]^=a[row][z];piv.push_back(col);row++;}
 vector<int> where(n,-1);for(int i=0;i<(int)piv.size();i++)where[piv[i]]=i;
 for(int z=0;z<q;z++){bool bad=false;for(int r=piv.size();r<n;r++)if((a[r][(n+z)>>6]>>((n+z)&63))&1){bad=true;break;}if(bad){cout<<-1<<'\n';continue;}vector<int> ans;for(int i=0;i<(int)piv.size();i++)if((a[i][(n+z)>>6]>>((n+z)&63))&1)ans.push_back(piv[i]+1);cout<<ans.size();for(int x:ans)cout<<' '<<x;cout<<'\n';}
}
