#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<array<int,3>> edges;
    for(int i=0;i<n-1;i++){ int u,v,w; scanf("%d %d %d",&u,&v,&w); edges.push_back({u,v,w}); }
    // force relations
    bool le[9][9]={};
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) le[i][j]=false;
    for(auto &e: edges){
        if(e[2]==1) le[e[0]][e[1]]=true;
        if(e[2]==2) le[e[1]][e[0]]=true;
    }
    // transitive closure
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) if(le[i][k]&&le[k][j]) le[i][j]=true;
    vector<int> p(n); for(int i=0;i<n;i++) p[i]=i+1;
    int cnt=0;
    do{
        int pos[9]={};
        for(int i=0;i<n;i++) pos[p[i]]=i;
        bool ok=true;
        for(int i=1;i<=n&&ok;i++)for(int j=1;j<=n;j++) if(le[i][j] && pos[i]>pos[j]){ok=false;break;}
        if(ok) cnt++;
    } while(next_permutation(p.begin(),p.end()));
    printf("%d\n", cnt%1000000007);
}
