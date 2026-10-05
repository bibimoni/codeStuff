#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAXN = 4005;
ll fac[MAXN], ifac[MAXN];
ll modpow(ll a, ll b) { ll r = 1; while (b) { if (b & 1) r = r * a % MOD; a = a * a % MOD; b >>= 1; } return r; }
ll C(int a, int b) { if (b < 0 || b > a || a < 0) return 0; return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD; }
int main() {
    int n; scanf("%d", &n);
    // adj[v]: (neighbour, vBeforeNeighbour) for FIXED edges only
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        if (w == 0) continue;
        int a, b;
        if (w == 1) { a = u; b = v; } else { a = v; b = u; }
        adj[a].push_back({b, 1});
        adj[b].push_back({a, 0});
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[n] = modpow(fac[n], MOD - 2);
    for (int i = n; i >= 1; i--) ifac[i - 1] = ifac[i] * i % MOD;
    vector<vector<ll>> dp(n);
    vector<int> sz(n, 0);
    vector<ll> tot(n, 0);
    vector<char> vis(n, 0);
    vector<int> par(n, -1);
    vector<int> roots;
    for (int r = 0; r < n; r++) {
        if (vis[r]) continue;
        roots.push_back(r);
        vector<int> ord, st = {r};
        vis[r] = 1;
        while (!st.empty()) {
            int v = st.back(); st.pop_back(); ord.push_back(v);
            for (auto &e : adj[v]) if (!vis[e.first]) { vis[e.first] = 1; par[e.first] = v; st.push_back(e.first); }
        }
        for (int idx = (int)ord.size() - 1; idx >= 0; idx--) {
            int v = ord[idx];
            vector<ll> f(2, 0); f[0] = 1;   // f[k]: k elements before v
            int L = 1;
            for (auto &e : adj[v]) {
                int c = e.first;
                if (c == par[v]) continue;
                int s = sz[c];
                // prefix sums of dp[c]
                vector<ll> pre(s + 1, 0);
                for (int y = 1; y <= s; y++) { pre[y] = pre[y - 1] + dp[c][y - 1]; pre[y] %= MOD; }
                vector<ll> nf(L + s + 1, 0);
                for (int k = 0; k <= L; k++) {
                    if (!f[k]) continue;
                    int rem = L - k - 1;   // elements after v
                    for (int y = 0; y <= s; y++) {
                        ll val = e.second ? (tot[c] - pre[y] + MOD) % MOD : pre[y];
                        if (!val) continue;
                        ll ways = C(k + y, y) * C(rem + s - y, s - y) % MOD;
                        nf[k + y] = (nf[k + y] + f[k] * val % MOD * ways) % MOD;
                    }
                }
                f.swap(nf); L += s;
            }
            sz[v] = L;
            dp[v] = f;
            ll tt = 0;
            for (int k = 0; k <= L; k++) tt = (tt + f[k]) % MOD;
            tot[v] = tt;
        }
    }
    ll ans = 1; int cur = 0;
    for (int r : roots) { ans = ans * tot[r] % MOD * C(cur + sz[r], sz[r]) % MOD; cur += sz[r]; }
    printf("%lld\n", ans);
    return 0;
}
