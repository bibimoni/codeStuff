#include <bits/stdc++.h>
using namespace std;

const long long CAP = 1000000000000000000LL;
long long dp[301][45151];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[0][0] = 1;
    for (int len = 1; len <= 300; ++len) {
        long long sum = 0;
        int lim = len * (len - 1) / 2;
        int mid = lim / 2;
        for (int inv = 0; inv <= mid; ++inv) {
            if (inv && dp[len][inv - 1] == CAP) {
                dp[len][inv] = CAP;
                continue;
            }
            sum += dp[len - 1][inv];
            if (inv >= len) sum -= dp[len - 1][inv - len];
            dp[len][inv] = min(CAP, sum);
        }
        for (int inv = mid + 1; inv <= lim; ++inv)
            dp[len][inv] = dp[len][lim - inv];
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long k;
        cin >> n >> m >> k;
        if (dp[n][m] < k) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> available(n);
        iota(available.begin(), available.end(), 1);
        for (int rem = n; rem; --rem) {
            for (int j = 0; j < rem; ++j) {
                long long ways = m >= j ? dp[rem - 1][m - j] : 0;
                if (k > ways) {
                    k -= ways;
                } else {
                    cout << available[j] << " \n"[rem == 1];
                    available.erase(available.begin() + j);
                    m -= j;
                    break;
                }
            }
        }
    }
}
