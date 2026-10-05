#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
    vector<int> p, sz;
    int comp=0;
    void reset(int n){ p.assign(n,-1); sz.assign(n,1); comp=0; }
    void activate(int x){ p[x]=x; comp++; }
    int find(int x){ while(p[x]!=x){ p[x]=p[p[x]]; x=p[x]; } return x; }
    bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(sz[a]<sz[b]) swap(a,b); p[b]=a; sz[a]+=sz[b]; comp--; return true; }
};

int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int n,m; scanf("%d %d",&n,&m);
        int N=n*m;
        vector<int> g(N);
        for(int i=0;i<N;i++) scanf("%d",&g[i]);
        int q; scanf("%d",&q);
        vector<int> imp(q);
        vector<char> destroyed(N,0);
        for(int i=0;i<q;i++){ int r,c; scanf("%d %d",&r,&c); imp[i]=(r-1)*m+(c-1); destroyed[imp[i]]=1; }
        DSU dsu; dsu.reset(N);
        ll V=0,E=0;
        vector<char> alive(N,0);
        auto opens=[&](int x,int dir)->bool{ return (g[x]>>dir)&1; };
        // dir bits: up=1(0), right=2(1), down=4(2), left=8(3)
        auto tryEdge=[&](int x,int y,int bx,int by){ // x has bit bx, y has bit by
            if(!alive[y]) return;
            if((g[x]&bx)&&(g[y]&by)){ E++; dsu.unite(x,y); }
        };
        // initial alive = junctions never destroyed
        for(int i=0;i<N;i++) if(g[i] && !destroyed[i]){ alive[i]=1; dsu.activate(i); V++; }
        for(int i=0;i<N;i++) if(alive[i]){
            int r=i/m,c=i%m;
            if(c+1<m) tryEdge(i, i+1, 2, 8);
            if(r+1<n) tryEdge(i, i+m, 4, 1);
        }
        vector<ll> ans(q+1);
        ans[q]=E-V+dsu.comp;
        for(int k=q;k>=1;k--){
            int x=imp[k-1];
            alive[x]=1; dsu.activate(x); V++;
            int r=x/m,c=x%m;
            if(c+1<m) tryEdge(x, x+1, 2, 8);
            if(c>0)   tryEdge(x, x-1, 8, 2);
            if(r+1<n) tryEdge(x, x+m, 4, 1);
            if(r>0)   tryEdge(x, x-m, 1, 4);
            ans[k-1]=E-V+dsu.comp;
        }
        for(int i=1;i<=q;i++) printf("%lld%c", ans[i], i<q?' ':'\n');
        if(q==0) printf("\n");
    }
    return 0;
}
