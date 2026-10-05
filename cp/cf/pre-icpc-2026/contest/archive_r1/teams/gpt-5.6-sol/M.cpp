#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull CAP = 1000000000000000000ULL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ull>> dp(301);
    dp[0] = {1};
    for (int len = 1; len <= 300; ++len) {
        int mx = len * (len - 1) / 2;
        dp[len].resize(mx + 1);
        __uint128_t window = 0;
        for (int inv = 0; inv <= mx; ++inv) {
            if (inv < (int)dp[len - 1].size()) window += dp[len - 1][inv];
            if (inv >= len) window -= dp[len - 1][inv - len];
            dp[len][inv] = window > CAP ? CAP : (ull)window;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ull k;
        cin >> n >> m >> k;
        if (dp[n][m] < k) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> left(n);
        iota(left.begin(), left.end(), 1);
        vector<int> answer;
        for (int len = n; len > 0; --len) {
            for (int rank = 0; rank < len; ++rank) {
                int rest = m - rank;
                ull ways = rest >= 0 && rest < (int)dp[len - 1].size()
                               ? dp[len - 1][rest]
                               : 0;
                if (k > ways) {
                    k -= ways;
                } else {
                    answer.push_back(left[rank]);
                    left.erase(left.begin() + rank);
                    m = rest;
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i)
            cout << answer[i] << (i + 1 == n ? '\n' : ' ');
    }
}
