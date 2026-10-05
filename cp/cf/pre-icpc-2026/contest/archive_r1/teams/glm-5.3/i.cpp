#include <bits/stdc++.h>
using namespace std;

static int par[200005];
int find(int x){ while(par[x]!=x){ par[x]=par[par[x]]; x=par[x]; } return x; }

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,m; scanf("%d %d",&n,&m);
        vector<int> g(n*m);
        for(auto&v:g) scanf("%d",&v);
        int q; scanf("%d",&q);
        vector<int> dr(q), dc(q);
        vector<char> dead(n*m,0);
        for(int i=0;i<q;i++){
            int r,c; scanf("%d %d",&r,&c); r--; c--;
            dr[i]=r; dc[i]=c;
            dead[r*m+c]=1;
        }
        for(int i=0;i<n*m;i++) par[i]=i;
        auto bit=[](int v,int b){return (v>>b)&1;};
        long long E=0, V=0, uni=0;
        for(int r=0;r<n;r++)for(int c=0;c<m;c++){
            int id=r*m+c;
            if(dead[id]) continue;
            V++;
            if(r>0 && !dead[id-m] && bit(g[id],0) && bit(g[id-m],2)){ E++; if(find(id)!=find(id-m)){par[find(id)]=find(id-m); uni++;} }
            if(c>0 && !dead[id-1] && bit(g[id],3) && bit(g[id-1],1)){ E++; if(find(id)!=find(id-1)){par[find(id)]=find(id-1); uni++;} }
        }
        long long cur = E - V + (V - uni);
        vector<long long> ans(q);
        for(int i=q-1;i>=0;i--){
            ans[i]=cur;
            int r=dr[i], c=dc[i], id=r*m+c;
            dead[id]=0;
            int k=0, s=0;
            if(r>0 && !dead[id-m] && bit(g[id],0) && bit(g[id-m],2)){ k++; if(find(id)!=find(id-m)){par[find(id)]=find(id-m); s++;} }
            if(r<n-1 && !dead[id+m] && bit(g[id],2) && bit(g[id+m],0)){ k++; if(find(id)!=find(id+m)){par[find(id)]=find(id+m); s++;} }
            if(c>0 && !dead[id-1] && bit(g[id],3) && bit(g[id-1],1)){ k++; if(find(id)!=find(id-1)){par[find(id)]=find(id-1); s++;} }
            if(c<m-1 && !dead[id+1] && bit(g[id],1) && bit(g[id+1],3)){ k++; if(find(id)!=find(id+1)){par[find(id)]=find(id+1); s++;} }
            cur += k - s;
        }
        if(q>0){
            for(int i=0;i<q;i++) printf("%lld%c", ans[i], i==q-1?'\n':' ');
        } else printf("\n");
    }
}
