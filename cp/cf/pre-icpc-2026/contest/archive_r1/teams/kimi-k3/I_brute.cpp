#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int n,m; scanf("%d %d",&n,&m);
        int N=n*m;
        vector<int> g(N);
        for(auto&x:g) scanf("%d",&x);
        int q; scanf("%d",&q);
        vector<pair<int,int>> imp(q);
        vector<char> alive(N);
        for(int i=0;i<N;i++) alive[i]=g[i]>0;
        for(auto&p:imp){ scanf("%d %d",&p.first,&p.second); p.first--; p.second--; }
        vector<long long> out;
        for(int k=0;k<=q;k++){
            vector<int> par(N);
            iota(par.begin(),par.end(),0);
            function<int(int)> f=[&](int x){ return par[x]==x?x:par[x]=f(par[x]); };
            long long V=0,E=0;
            set<int> comps;
            for(int i=0;i<N;i++) if(alive[i]){
                V++;
                int r=i/m,c=i%m;
                if(c+1<m && alive[i+1] && (g[i]&2) && (g[i+1]&8)){ E++; par[f(i)]=f(i+1); }
                if(r+1<n && alive[i+m] && (g[i]&4) && (g[i+m]&1)){ E++; par[f(i)]=f(i+m); }
            }
            for(int i=0;i<N;i++) if(alive[i]) comps.insert(f(i));
            if(k>=1) out.push_back(E-V+(long long)comps.size());
            if(k<q){ alive[imp[k].first*m+imp[k].second]=0; }
        }
        for(size_t i=0;i<out.size();i++) printf("%lld%c", out[i], i+1<out.size()?' ':'\n');
        if(q==0) printf("\n");
    }
    return 0;
}
