#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int n;
vector<vector<int>> adj;  // signed: + = neighbour AFTER me, - = neighbour BEFORE me
vector<int> par, pdir, sz, vis;
vector<ll> fac, ifac;

ll modpow(ll a, ll e){ ll r=1; while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1; } return r; }
ll C(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    cin >> n;
    adj.assign(n, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        if (w == 0) continue;
        // w=1: u before v.  w=2: v before u.  Both mean "first-listed endpoint
        // of the DIRECTED edge is before the second", so encode identically with
        // (w==2) as (edge v->u).
        {
            int x = u, y = v;
            if (w == 2) { x = v; y = u; }
            adj[x].push_back(y);
            adj[y].push_back(-x - 1);
        }
    }
    fac.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac.assign(n + 1, 1);
    ifac[n] = modpow(fac[n], MOD - 2);
    for (int i = n; i >= 1; i--) ifac[i - 1] = ifac[i] * i % MOD;

    // iterative postorder over all components
    vector<int> root;
    vector<vector<ll>> f(n);
    vector<int> stk;
    vis.assign(n, 0);
    // build parent arrays via DFS
    vector<int> order;
    par.assign(n, -1);
    pdir.assign(n, 0);
    for (int r = 0; r < n; r++) {
        if (vis[r]) continue;
        root.push_back(r);
        vis[r] = 1;
        stk.push_back(r);
        while (!stk.empty()) {
            int v = stk.back(); stk.pop_back();
            order.push_back(v);
            for (int e : adj[v]) {
                int u = e >= 0 ? e : -e - 1;
                if (vis[u]) continue;
                vis[u] = 1;
                par[u] = v;
                pdir[u] = (e >= 0) ? 1 : 0;  // 1: child AFTER v ; 0: child BEFORE v
                stk.push_back(u);
            }
        }
    }
    // process in reverse discovery order (postorder-ish)
    sz.assign(n, 1);
    for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
        int v = order[idx];
        vector<ll> acc(1, 1);
        int P = 0;
        for (int e : adj[v]) {
            int u = e >= 0 ? e : -e - 1;
            if (par[u] != v) continue;
            int sc = sz[u];
            vector<ll> g(sc + 1, 0);
            ll run = 0;
            if (pdir[u] == 1) {
                // v before u: the x elements before u may all sit before v.
                // g[y] = #ways with exactly y of sub(u) before v
                run = 0;
                for (int y = sc; y >= 0; y--) {
                    if (y < sc) run = (run + f[u][y]) % MOD;
                    g[y] = run;
                }
            } else {
                // u before v: the x elements before u AND u itself are before v,
                // so at least x+1 of sub(u) precede v.  g[y] = sum_{x<y} f[x]
                run = 0;
                for (int y = 0; y <= sc; y++) {
                    if (y > 0) run = (run + f[u][y - 1]) % MOD;
                    g[y] = run;
                }
            }
            vector<ll> nc(P + sc + 1, 0);
            for (int p = 0; p <= P; p++) {
                if (!acc[p]) continue;
                ll A = acc[p];
                for (int y = 0; y <= sc; y++) {
                    if (!g[y]) continue;
                    ll w = A * g[y] % MOD;
                    w = w * C(p + y, y) % MOD;
                    w = w * C((P - p) + (sc - y), sc - y) % MOD;
                    nc[p + y] += w;
                    if (nc[p + y] >= MOD) nc[p + y] -= MOD;
                }
            }
            P += sc;
            acc.swap(nc);
            vector<ll>().swap(f[u]);
        }
        f[v] = acc;
        sz[v] = P + 1;
    }
    ll ans = fac[n];
    for (int r : root) {
        ll e = 0;
        for (ll x : f[r]) e = (e + x) % MOD;
        ans = ans * e % MOD * ifac[sz[r]] % MOD;
    }
    cout << ans % MOD << "\n";
}
