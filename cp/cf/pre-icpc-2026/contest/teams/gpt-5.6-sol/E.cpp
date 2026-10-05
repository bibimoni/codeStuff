#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

long long power(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Edge { int to, relation; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<Edge>> graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        int relation = w == 0 ? 0 : (w == 1 ? 1 : -1);
        graph[u].push_back({v, relation});
        graph[v].push_back({u, -relation});
    }
    vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
    invFact[n] = power(fact[n], MOD - 2);
    for (int i = n; i; --i) invFact[i - 1] = invFact[i] * i % MOD;
    auto choose = [&](int a, int b) -> long long {
        return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
    };

    vector<int> parent(n, -1), relationToChild(n), order = {0};
    for (int at = 0; at < (int)order.size(); ++at) {
        int v = order[at];
        for (auto [u, relation] : graph[v]) if (u != parent[v]) {
            parent[u] = v;
            relationToChild[u] = relation;
            order.push_back(u);
        }
    }
    vector<vector<int>> dp(n);
    for (int oi = n - 1; oi >= 0; --oi) {
        int v = order[oi];
        dp[v] = {1};
        for (auto [u, ignored] : graph[v]) if (parent[u] == v) {
            int a = dp[v].size(), b = dp[u].size();
            vector<int> prefix(b + 1), next(a + b);
            for (int j = 0; j < b; ++j) prefix[j + 1] = (prefix[j] + dp[u][j]) % MOD;
            for (int i = 0; i < a; ++i) for (int x = 0; x <= b; ++x) {
                long long childWays;
                if (relationToChild[u] == 0) childWays = prefix[b];
                else if (relationToChild[u] == 1) childWays = (prefix[b] - prefix[x] + MOD) % MOD;
                else childWays = prefix[x];
                long long ways = dp[v][i] * childWays % MOD;
                ways = ways * choose(i + x, i) % MOD;
                ways = ways * choose(a - 1 - i + b - x, a - 1 - i) % MOD;
                next[i + x] = (next[i + x] + ways) % MOD;
            }
            dp[v].swap(next);
            vector<int>().swap(dp[u]);
        }
    }
    long long answer = 0;
    for (int ways : dp[0]) answer = (answer + ways) % MOD;
    cout << answer << '\n';
}
