#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p, r;
    DSU(int n){ p.resize(n); r.assign(n,0); iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a, int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,m; scanf("%d %d",&n,&m);
        vector<vector<int>> g(n, vector<int>(m));
        int N = n*m;
        vector<int> id(N, -1);
        int cnt = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            scanf("%d",&g[i][j]);
            if(g[i][j]) id[i*m+j] = cnt++;
        }
        int q; scanf("%d",&q);
        vector<pair<int,int>> impacts(q);
        vector<char> hit(N, 0);
        for(int i=0;i<q;i++){
            int r,c; scanf("%d %d",&r,&c); --r;--c;
            impacts[i] = {r,c};
            hit[r*m+c] = 1;
        }
        DSU dsu(cnt);
        vector<char> present(N, 0);
        long long V = 0, E = 0, C = 0;
        auto idAt = [&](int i, int j)->int{
            if(i<0||i>=n||j<0||j>=m) return -1;
            return id[i*m+j];
        };
        int di[4] = {-1,1,0,0}, dj[4] = {0,0,-1,1};
        int bit[4] = {1,4,8,2};
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(id[i*m+j]>=0 && !hit[i*m+j]) present[i*m+j] = 1;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(!present[i*m+j]) continue;
            V++;
            C++;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            int u = id[i*m+j];
            if(u<0 || !present[i*m+j]) continue;
            for(int d=1; d<4; d+=2){
                int v = idAt(i+di[d], j+dj[d]);
                if(v<0 || !present[(i+di[d])*m+(j+dj[d])]) continue;
                if((g[i][j] & bit[d]) && (g[i+di[d]][j+dj[d]] & bit[d^1])){
                    E++;
                    if(dsu.unite(u, v)) C--;
                }
            }
        }
        vector<long long> rank(q+1);
        rank[0] = E - V + C;
        for(int k=1;k<=q;k++){
            auto [r,c] = impacts[q-k];
            int u = id[r*m+c];
            present[r*m+c] = 1;
            V++;
            C++;
            for(int d=0; d<4; d++){
                int ni = r+di[d], nj = c+dj[d];
                int v = idAt(ni,nj);
                if(v<0 || id[ni*m+nj]<0 || !present[ni*m+nj]) continue;
                if((g[r][c] & bit[d]) && (g[ni][nj] & bit[d^1])){
                    E++;
                    if(dsu.unite(u, v)) C--;
                }
            }
            rank[k] = E - V + C;
        }
        for(int i=1;i<=q;i++){
            if(i>1) printf(" ");
            printf("%lld", rank[q-i]);
        }
        printf("\n");
    }
}
