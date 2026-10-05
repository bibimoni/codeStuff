#include <bits/stdc++.h>
using namespace std;
vector<int> dsu;
int findd(int x){ while(dsu[x]!=x){ dsu[x]=dsu[dsu[x]]; x=dsu[x]; } return x; }
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,m; scanf("%d %d",&n,&m);
        int nm=n*m;
        vector<int> g(nm);
        for(int i=0;i<nm;i++) scanf("%d",&g[i]);
        int q; scanf("%d",&q);
        vector<int> imp(q);
        vector<char> dead(nm,0);
        for(int i=0;i<q;i++){ int r,c; scanf("%d %d",&r,&c); imp[i]=(r-1)*m+(c-1); dead[imp[i]]=1; }
        // ids: cell idx; junction if g!=0
        dsu.resize(nm);
        for(int i=0;i<nm;i++) dsu[i]=i;
        vector<char> present(nm,0);
        // loops counter; edges added implicitly via unite results
        long long loops=0;
        auto addv=[&](int v){
            present[v]=1;
            int r=v/m, c=v%m;
            // check right and down neighbors only (each edge once)
            // but when adding v, neighbor might be added earlier: handle edges from v to present neighbors in all 4 dirs
            const int dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1}, bitv[4]={1,2,4,8}, bitw[4]={4,8,1,2};
            for(int d=0;d<4;d++){
                int nr=r+dr[d], nc=c+dc[d];
                if(nr<0||nr>=n||nc<0||nc>=m) continue;
                int w=nr*m+nc;
                if(!present[w]||!g[w]) continue;
                if(!(g[v]&bitv[d])||!(g[w]&bitw[d])) continue;
                // edge v-w
                int rv=findd(v), rw=findd(w);
                if(rv==rw) loops++;
                else dsu[rv]=rw;
            }
        };
        for(int v=0;v<nm;v++) if(g[v] && !dead[v]) addv(v);
        vector<long long> ans(q+1);
        ans[q]=loops;
        for(int i=q-1;i>=0;i--){ addv(imp[i]); ans[i]=loops; }
        for(int i=1;i<=q;i++) printf("%lld%c",ans[i],(i==q)?'\n':' ');
        if(q==0) printf("\n");
    }
    return 0;
}
