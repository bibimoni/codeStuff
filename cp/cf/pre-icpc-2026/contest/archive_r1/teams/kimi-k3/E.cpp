#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int MAXN = 4005;
ll fact[MAXN], invfact[MAXN];
ll pw(ll b, ll e){ ll r=1; while(e){ if(e&1) r=r*b%MOD; b=b*b%MOD; e>>=1;} return r; }
ll C(int n, int k){ if(k<0||k>n) return 0; return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD; }

int n;
vector<pair<int,int>> adj[MAXN]; // (neighbor, dir) dir=0: v before nb (v->nb), 1: nb before v
vector<vector<ll>> memo;
vector<char> vis;

// returns f_v: f_v[j] = # lin-ext of subtree with exactly j elements before v
vector<ll> dfs(int v, int parent){
    vis[v]=1;
    vector<ll> fv(1,1);
    int szA = 1;
    for(auto [c, dir]: adj[v]){
        if(c==parent || vis[c]) continue;
        // constraint between v and c: dir==0 means v->c (v before c): case B; dir==1: c before v: case A
        vector<ll> fc = dfs(c, v);
        int szB = fc.size();
        // build q[t], t in 0..szB
        vector<ll> q(szB+1, 0);
        if(dir==0){ // v before c: suffix sums of fc: q[t] = sum_{j>=t} fc[j], t in 0..szB-1
            ll s=0;
            for(int t=szB-1;t>=0;t--){ s+=fc[t]; if(s>=MOD)s-=MOD; q[t]=s; }
        } else { // c before v: prefix: q[t] = sum_{j<=t-1} fc[j], t in 1..szB
            ll s=0;
            for(int t=1;t<=szB;t++){ s+=fc[t-1]; if(s>=MOD)s-=MOD; q[t]=s; }
        }
        vector<ll> fv2(szA+szB, 0);
        for(int x=0;x<szA;x++) if(fv[x]){
            ll ax = fv[x];
            for(int t=0;t<=szB;t++) if(q[t]){
                ll ways = ax * q[t] % MOD * C(x+t, x) % MOD * C((szA-1-x)+(szB-t), szB-t) % MOD;
                fv2[x+t] = (fv2[x+t] + ways) % MOD;
            }
        }
        fv = move(fv2);
        szA += szB;
    }
    return fv;
}

int main(){
    fact[0]=1; for(int i=1;i<MAXN;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXN-1]=pw(fact[MAXN-1], MOD-2);
    for(int i=MAXN-2;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        if(w==0) continue;
        // w=1: u before v (u->v); w=2: v before u
        if(w==1){ adj[u].push_back({v,0}); adj[v].push_back({u,1}); }
        else { adj[v].push_back({u,0}); adj[u].push_back({v,1}); }
    }
    vis.assign(n+1,0);
    ll ans = fact[n];
    for(int i=1;i<=n;i++) if(!vis[i]){
        vector<ll> f = dfs(i, -1);
        ll L=0; for(ll x: f){ L+=x; if(L>=MOD)L-=MOD; }
        ans = ans * L % MOD * invfact[f.size()] % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
