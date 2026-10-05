#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
vector<ll> fct, ifct;
ll pw(ll b, ll e){ ll r=1; b%=MOD; while(e){ if(e&1) r=r*b%MOD; b=b*b%MOD; e>>=1;} return r; }
int main(){
    int n; scanf("%d",&n);
    fct.assign(n+2,1); for(int i=1;i<=n+1;i++) fct[i]=fct[i-1]*i%MOD;
    ifct.assign(n+2,1); ifct[n+1]=pw(fct[n+1],MOD-2);
    for(int i=n+1;i>0;i--) ifct[i-1]=ifct[i]*i%MOD;
    vector<vector<pair<int,int>>> adj(n+1); // (nbr, bigger: 1 if nbr is bigger than me)
    for(int i=0;i<n-1;i++){
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        if(w==1){ adj[u].push_back({v,1}); adj[v].push_back({u,0}); }
        else if(w==2){ adj[u].push_back({v,0}); adj[v].push_back({u,1}); }
    }
    vector<char> vis(n+1,0);
    vector<vector<ll>> Larr(n+1), Rarr(n+1);
    vector<int> szv(n+1,0), rel(n+1,0), par(n+1,0);
    vector<vector<int>> kids(n+1);
    ll ans = fct[n];
    for(int root=1; root<=n; root++) if(!vis[root]){
        vector<int> bfs; bfs.push_back(root); vis[root]=1;
        for(size_t i=0;i<bfs.size();i++){
            int u=bfs[i];
            for(auto pr: adj[u]){
                int v=pr.first, bigger=pr.second;
                if(vis[v]) continue;
                vis[v]=1;
                rel[v] = bigger ? 2 : 1; // 2: parent<=child (child above, U in post); 1: child<=parent (D in pre)
                par[v]=u;
                kids[u].push_back(v);
                bfs.push_back(v);
            }
        }
        for(int i=(int)bfs.size()-1;i>=0;i--){
            int u=bfs[i];
            int S=1;
            for(int c: kids[u]) S+=szv[c];
            vector<ll> conv(1,1);
            for(int c: kids[u]){
                int sc=szv[c];
                vector<ll> p(sc+1);
                for(int a=0;a<=sc;a++){
                    ll w = (rel[c]==1) ? Larr[c][a] : Rarr[c][sc-a];
                    p[a] = w * ifct[a]%MOD * ifct[sc-a]%MOD;
                }
                vector<ll> nc((int)conv.size()+sc, 0);
                for(size_t x=0;x<conv.size();x++){
                    if(!conv[x]) continue;
                    for(int y=0;y<=sc;y++){
                        if(!p[y]) continue;
                        nc[x+y]=(nc[x+y]+conv[x]*p[y])%MOD;
                    }
                }
                conv.swap(nc);
                Larr[c].clear(); Larr[c].shrink_to_fit();
                Rarr[c].clear(); Rarr[c].shrink_to_fit();
            }
            int S1=S-1;
            vector<ll> f(S,0);
            ll G=0;
            for(int A=0;A<S;A++){
                ll cv = (A<(int)conv.size()) ? conv[A] : 0;
                f[A] = cv * fct[A]%MOD * fct[S1-A]%MOD;
                G=(G+f[A])%MOD;
            }
            vector<ll> Lu(S+1,0);
            for(int a=1;a<=S;a++) Lu[a]=(Lu[a-1]+f[a-1])%MOD;
            vector<ll> Ru(S+1,0);
            for(int b=1;b<=S;b++) Ru[b]=(Ru[b-1]+f[S-b])%MOD;
            Larr[u]=std::move(Lu); Rarr[u]=std::move(Ru); szv[u]=S;
            if(u==root) ans = ans * G % MOD * ifct[S] % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
