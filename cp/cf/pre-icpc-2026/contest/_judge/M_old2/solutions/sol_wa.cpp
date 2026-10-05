#include <bits/stdc++.h>
using namespace std;

const long long CAP = 1000000000000000000LL;

struct CappedSum {
    int whole = 0;
    long long rem = 0;
    void add(long long x) {
        rem += x;
        if (rem >= CAP) rem -= CAP, ++whole;
    }
    void remove(long long x) {
        if (rem < x) rem += CAP, --whole;
        rem -= x;
    }
    long long value() const { return whole > 0 ? CAP : rem; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long k;
        cin >> n >> m >> k;
        vector<vector<long long>> dp(n + 1);
        dp[0] = {1};
        for (int len = 1; len <= n; ++len) {
            dp[len].assign(len * (len - 1) / 2 + 1, 0);
            CappedSum window;
            for (int inv = 0; inv < (int)dp[len].size(); ++inv) {
                if (inv < (int)dp[len - 1].size()) window.add(dp[len - 1][inv]);
                if (inv >= len && inv - len < (int)dp[len - 1].size()) window.remove(dp[len - 1][inv - len]);
                dp[len][inv] = window.value();
            }
        }
        if (dp[n][m] < k) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        for (int len = n; len; --len) {
            for (int r = 0; r < len; ++r) {
                // Wrong: counts larger remaining values instead of smaller ones.
                int left = m - (len - 1 - r);
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
