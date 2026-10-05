// brute for L: DFS all simple paths on cycle+hub, small n
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll q;
vector<ll> aa, bb;
vector<vector<pair<int,ll>>> g;

ll best;
void dfs(int u, int t, ll cost, vector<char>& vis){
    if(u==t){ best=min(best,cost); return; }
    for(auto&e:g[u]){
        int v=e.first;
        if(vis[v]) continue;
        vis[v]=1;
        dfs(v,t,cost+e.second,vis);
        vis[v]=0;
    }
}

int main(){
    int t; if(scanf("%d",&t)!=1) return 0;
    while(t--){
        scanf("%d %lld",&n,&q);
        aa.resize(n+1); bb.resize(n+1);
        for(int i=1;i<=n;i++) scanf("%lld",&aa[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&bb[i]);
        auto rebuild=[&](){
            g.assign(n+2,{});
            for(int i=1;i<=n;i++){ int j=i%n+1; g[i].push_back({j,aa[i]}); g[j].push_back({i,aa[i]}); }
            for(int i=1;i<=n;i++){ g[i].push_back({n+1,bb[i]}); g[n+1].push_back({i,bb[i]}); }
        };
        rebuild();
        while(q--){
            int type; scanf("%d",&type);
            if(type==1){
                int s,t2; scanf("%d %d",&s,&t2);
                vector<char> vis(n+2,0);
                best=LLONG_MAX; vis[s]=1;
                dfs(s,t2,0,vis);
                printf("%lld\n", best);
            } else if(type==2){
                int x; ll w; scanf("%d %lld",&x,&w);
                aa[x]=w; rebuild();
            } else {
                int x; ll w; scanf("%d %lld",&x,&w);
                bb[x]=w; rebuild();
            }
        }
    }
}
