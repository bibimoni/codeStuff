#include <bits/stdc++.h>
using namespace std;

const long long CAP = 1000000000000000000LL;

static vector<vector<long long>> buildSlow(int n) {
    vector<vector<long long>> dp(n + 1);
    dp[0] = {1};
    for (int len = 1; len <= n; ++len) {
        dp[len].assign(len * (len - 1) / 2 + 1, 0);
        for (int inv = 0; inv < (int)dp[len].size(); ++inv) {
            for (int firstRank = 0; firstRank < len && firstRank <= inv; ++firstRank) {
                int rest = inv - firstRank;
                if (rest < (int)dp[len - 1].size())
                    dp[len][inv] = min(CAP, dp[len][inv] + dp[len - 1][rest]);
            }
        }
    }
    return dp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long k;
        cin >> n >> m >> k;
        vector<vector<long long>> dp = buildSlow(n);
        if (dp[n][m] < k) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        for (int len = n; len; --len) {
            // This straightforward approach recomputes all suffix counts after
            // fixing every prefix element instead of retaining one table.
            dp = buildSlow(len - 1);
            for (int r = 0; r < len; ++r) {
                int left = m - r;
                long long cnt = left >= 0 && left < (int)dp[len - 1].size() ? dp[len - 1][left] : 0;
                if (k > cnt) k -= cnt;
                else {
                    cout << a[r] << (len == 1 ? '\n' : ' ');
                    a.erase(a.begin() + r);
                    m = left;
                    break;
                }
            }
        }
    }
}
