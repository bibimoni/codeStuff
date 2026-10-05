#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> a, b;
// vertices: 1..n islands, n+1 = hub
// edges: cycle a_i (1..n), flights b_i (island i <-> hub)
ll best;
vector<char> vis;
void dfs(int v, int target, ll cost){
    if(cost >= (ll)4e18/2) return;
    if(v==target){ best=min(best,cost); return; }
    vis[v]=1;
    for(int i=1;i<=n;i++){
        if(i<=n){
            // cycle edge i connects i, i%n+1
        }
    }
    // from island v: cycle edges
    for(int i=1;i<=n;i++){
        int u=i, w=i%n+1;
        if(v==u && !vis[w]) dfs(w,target,cost+a[i]);
        else if(v==w && !vis[u]) dfs(u,target,cost+a[i]);
    }
    if(v<=n){ if(!vis[n+1]) dfs(n+1,target,cost+b[v]); }
    else {
        for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,target,cost+b[i]);
    }
    vis[v]=0;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int q; scanf("%d %d",&n,&q);
        a.assign(n+1,0); b.assign(n+1,0);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        while(q--){
            int tp; scanf("%d",&tp);
            if(tp==1){
                int s,t2; scanf("%d %d",&s,&t2);
                best=LLONG_MAX; vis.assign(n+2,0);
                dfs(s,t2,0);
                printf("%lld\n", best);
            } else if(tp==2){
                int x; ll w; scanf("%d %lld",&x,&w); a[x]=w;
            } else {
                int x; ll w; scanf("%d %lld",&x,&w); b[x]=w;
            }
        }
    }
}
