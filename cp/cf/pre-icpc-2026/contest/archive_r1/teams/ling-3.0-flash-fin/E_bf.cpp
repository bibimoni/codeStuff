#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long power(long long base, long long exp, long long mod) {
    long long result = 1; base %= mod;
    while (exp > 0) { if (exp & 1) result = result * base % mod; base = base * base % mod; exp >>= 1; }
    return result;
}
int main(){
    int n; scanf("%d", &n);
    vector<vector<int>> before(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        if (w == 1) before[v].push_back(u);
        else if (w == 2) before[u].push_back(v);
    }
    if (n <= 20) {
        vector<long long> dp(1<<n, 0);
        dp[0] = 1;
        for (int mask = 0; mask < (1<<n); mask++) {
            if (!dp[mask]) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1<<v)) continue;
                bool ok = true;
                for (int u : before[v+1]) {
                    if (!(mask & (1<<(u-1)))) { ok = false; break; }
                }
                if (ok) dp[mask|(1<<v)] = (dp[mask|(1<<v)] + dp[mask]) % MOD;
            }
        }
        printf("%lld\n", dp[(1<<n)-1]);
    } else {
        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1, 0);
        for (int u = 1; u <= n; u++) {
            for (int v : before[u]) {
                adj[u].push_back(v); adj[v].push_back(u);
                indeg[u]++;
            }
        }
        vector<int> sz(n+1, 0);
        vector<bool> visited(n+1, false);
        function<void(int,int)> dfs = [&](int u, int p) {
            visited[u] = true; sz[u] = 1;
            for (int v : adj[u]) { if (v == p) continue; dfs(v,u); sz[u] += sz[v]; }
        };
        int root = -1;
        for (int i = 1; i <= n; i++) { if (!visited[i] && indeg[i] == 0) { dfs(i,-1); root = i; } }
        if (root == -1) {
            for (int i = 1; i <= n; i++) { if (!visited[i]) { dfs(i,-1); root = i; } }
        }
        for (int i = 1; i <= n; i++) { if (!visited[i]) sz[i] = 1; }
        long long fact = 1;
        for (int i = 1; i <= n; i++) fact = fact * i % MOD;
        long long prod = 1;
        for (int i = 1; i <= n; i++) prod = prod * sz[i] % MOD;
        printf("%lld\n", fact % MOD * power(prod, MOD - 2, MOD) % MOD);
    }
}
