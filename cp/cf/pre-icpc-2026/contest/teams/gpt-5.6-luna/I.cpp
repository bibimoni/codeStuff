#include <bits/stdc++.h>
using namespace std;
struct DSU{vector<int>p,s;DSU(int n):p(n,-1),s(n,1){}int f(int x){return p[x]<0?x:p[x]=f(p[x]);}bool join(int a,int b){a=f(a);b=f(b);if(a==b)return false;if(-p[a]<-p[b])swap(a,b);p[a]+=p[b];p[b]=a;return true;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;int N=n*m;vector<int>g(N);for(int&x:g)cin>>x;int q;cin>>q;vector<int>hit(q);vector<char>active(N,0);for(int i=0;i<N;i++)active[i]=g[i]!=0;for(int&i:hit){int r,c;cin>>r>>c;i=(r-1)*m+c-1;active[i]=0;}
 DSU d(N);long long cyc=0;auto addEdge=[&](int u,int v){if(!d.join(u,v))cyc++;};int dr[4]={-1,0,1,0},dc[4]={0,1,0,-1},bit[4]={1,2,4,8};
 for(int r=0;r<n;r++)for(int c=0;c<m;c++){int u=r*m+c;if(!active[u])continue;for(int z=0;z<4;z++)if((g[u]&bit[z])&&r+dr[z]>=0&&r+dr[z]<n&&c+dc[z]>=0&&c+dc[z]<m){int v=(r+dr[z])*m+c+dc[z];if(v>u&&active[v]&&(g[v]&bit[z^2]))addEdge(u,v);}}
 vector<long long>ans(q);if(q)ans[q-1]=cyc;for(int i=q-1;i>=1;i--){int u=hit[i];active[u]=1;d.p[u]=-1;for(int z=0;z<4;z++){int r=u/m+dr[z],c=u%m+dc[z];if(r>=0&&r<n&&c>=0&&c<m){int v=r*m+c;if(active[v]&&(g[u]&bit[z])&&(g[v]&bit[z^2]))addEdge(u,v);}}ans[i-1]=cyc;}
 for(int i=0;i<q;i++)cout<<ans[i]<<(i+1==q?'\n':' ');if(q==0)cout<<'\n';}
}
