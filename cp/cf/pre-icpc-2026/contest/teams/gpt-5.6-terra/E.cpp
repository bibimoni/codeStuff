#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        // Direction is relative to u -> v: 1 means u before v, 2 means v before u.
        graph[u].push_back({v, w});
        graph[v].push_back({u, w == 1 ? 2 : w == 2 ? 1 : 0});
    }
    vector<vector<long long>> comb(n + 1, vector<long long>(n + 1));
    for (int i = 0; i <= n; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }
    function<pair<int, vector<long long>>(int, int)> dfs = [&](int u, int parent) {
        int size = 1;
        vector<long long> dp(1, 1);
        for (auto [v, direction] : graph[u]) if (v != parent) {
            auto [child_size, child] = dfs(v, u);
            vector<long long> prefix(child_size + 1), suffix(child_size + 1);
            for (int j = 0; j < child_size; ++j) prefix[j + 1] = (prefix[j] + child[j]) % MOD;
            for (int j = child_size - 1; j >= 0; --j) suffix[j] = (suffix[j + 1] + child[j]) % MOD;
            vector<long long> next(size + child_size);
            for (int i = 0; i < size; ++i) for (int x = 0; x <= child_size; ++x) {
                long long allowed;
                if (direction == 1) allowed = suffix[x];       // u before v
                else if (direction == 2) allowed = prefix[x];  // v before u
                else allowed = prefix[child_size];
                long long ways = comb[i + x][i] * comb[size - i - 1 + child_size - x][size - i - 1] % MOD;
                next[i + x] = (next[i + x] + dp[i] * allowed % MOD * ways) % MOD;
            }
            size += child_size;
            dp = move(next);
        }
        return pair{size, dp};
    };
    auto [size, dp] = dfs(0, -1);
    long long answer = 0;
    for (long long x : dp) answer = (answer + x) % MOD;
    cout << answer << '\n';
}
