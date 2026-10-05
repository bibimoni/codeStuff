#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll best;
void dfs(int u, int t, ll cost, vector<ll>& a, vector<ll>& b, vector<char>& vis){
    if(u==t){ best=min(best,cost); return; }
    if(u<=n){
        int v = u%n+1; // cw
        if(!vis[v]){ vis[v]=1; dfs(v,t,cost+a[u],a,b,vis); vis[v]=0; }
        int w = (u==1?n:u-1); // ccw
        if(!vis[w]){ int ei = w; vis[w]=1; dfs(w,t,cost+a[ei],a,b,vis); vis[w]=0; }
        if(!vis[n+1]){ vis[n+1]=1; dfs(n+1,t,cost+b[u],a,b,vis); vis[n+1]=0; }
    } else {
        for(int i=1;i<=n;i++) if(!vis[i]){ vis[i]=1; dfs(i,t,cost+b[i],a,b,vis); vis[i]=0; }
    }
}
int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int q; scanf("%d %d",&n,&q);
        vector<ll> a(n+1), b(n+1);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        while(q--){
            int ty; scanf("%d",&ty);
            if(ty==1){
                int s,t; scanf("%d %d",&s,&t);
                best = LLONG_MAX/4;
                vector<char> vis(n+2,0); vis[s]=1;
                dfs(s,t,0,a,b,vis);
                printf("%lld\n", best);
            } else if(ty==2){ int x; ll w; scanf("%d %lld",&x,&w); a[x]=w; }
            else { int x; ll w; scanf("%d %lld",&x,&w); b[x]=w; }
        }
    }
    return 0;
}
