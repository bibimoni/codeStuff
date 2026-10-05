#include <bits/stdc++.h>
using namespace std;

const long long INF = (long long)1e18 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    vector<tuple<int, int, long long>> queries(T);
    int max_n = 0;
    for (auto& [n, m, k] : queries) {
        cin >> n >> m >> k;
        max_n = max(max_n, n);
    }
    
    int max_inv = max_n * (max_n - 1) / 2;
    vector<vector<long long>> dp(max_n + 1, vector<long long>(max_inv + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        int max_inv_i = i * (i - 1) / 2;
        for (int j = 0; j <= max_inv_i; ++j) {
            long long sum = 0;
            for (int p = 0; p <= min(i - 1, j); ++p) {
                sum += dp[i-1][j-p];
                if (sum >= INF) { sum = INF; break; }
            }
            dp[i][j] = sum;
        }
    }
    
    for (auto [n, m, k] : queries) {
        if (m > n * (n - 1) / 2) {
            cout << -1 << '\n';
            continue;
        }
        if (dp[n][m] < k) {
            cout << -1 << '\n';
            continue;
        }
        
        vector<int> ans;
        vector<bool> used(n + 1, false);
        int rem = n;
        int cur_m = m;
        long long cur_k = k;
        
        for (int pos = 0; pos < n; ++pos) {
            for (int x = 1; x <= n; ++x) {
                if (used[x]) continue;
                int smaller_rem = 0;
                for (int y = 1; y < x; ++y) if (!used[y]) smaller_rem++;
                if (smaller_rem > cur_m) continue;
                long long ways = dp[rem - 1][cur_m - smaller_rem];
                if (ways >= cur_k) {
                    ans.push_back(x);
                    used[x] = true;
                    cur_m -= smaller_rem;
                    rem--;
                    break;
                } else {
                    cur_k -= ways;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}