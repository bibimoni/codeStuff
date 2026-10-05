#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,m; scanf("%d %d",&n,&m);
        vector<vector<int>> g(n, vector<int>(m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++) scanf("%d",&g[i][j]);
        int q; scanf("%d",&q);
        vector<pair<int,int>> imp(q);
        for(auto &pr:imp){ scanf("%d %d",&pr.first,&pr.second); pr.first--; pr.second--; }
        vector<vector<char>> alive(n, vector<char>(m,1));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++) if(g[i][j]==0) alive[i][j]=0;
        int dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1};
        int needS[4]={1,2,4,8}, needN[4]={4,8,1,2};
        for(int s=0;s<q;s++){
            alive[imp[s].first][imp[s].second]=0;
            long long E=0,V=0,C=0;
            vector<vector<char>> vis(n, vector<char>(m,0));
            for(int i=0;i<n;i++)for(int j=0;j<m;j++){
                if(!alive[i][j]||vis[i][j]) continue;
                C++; queue<pair<int,int>> qu; qu.push({i,j}); vis[i][j]=1;
                while(!qu.empty()){
                    auto [r,c]=qu.front(); qu.pop(); V++;
                    for(int d=0; d<4; d++){
                        if(!(g[r][c]&needS[d])) continue;
                        int rr=r+dr[d], cc=c+dc[d];
                        if(rr<0||rr>=n||cc<0||cc>=m||!alive[rr][cc]) continue;
                        if(!(g[rr][cc]&needN[d])) continue;
                        if(d==1||d==2) E++; // count each edge once: right from left end, down from top end
                        if(!vis[rr][cc]){vis[rr][cc]=1; qu.push({rr,cc});}
                    }
                }
            }
            printf("%lld ", E-V+C);
        }
        printf("\n");
    }
}
