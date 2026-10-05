#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 LIM = 1000000000000000000LL;

struct CappedSum {
    int whole = 0;
    int64 rem = 0;
    void add(int64 x) {
        rem += x;
        if (rem >= LIM) rem -= LIM, ++whole;
    }
    void remove(int64 x) {
        if (rem < x) rem += LIM, --whole;
        rem -= x;
    }
    int64 value() const { return whole > 0 ? LIM : rem; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        int64 k;
        cin >> n >> m >> k;

        vector<vector<int64>> dp(n + 1);
        dp[0] = {1};
        for (int len = 1; len <= n; ++len) {
            int maxInv = len * (len - 1) / 2;
            int prevMax = (len - 1) * (len - 2) / 2;
            dp[len].assign(maxInv + 1, 0);
            CappedSum window;
            for (int inv = 0; inv <= maxInv; ++inv) {
                if (inv <= prevMax) window.add(dp[len - 1][inv]);
                if (inv - len >= 0 && inv - len <= prevMax)
                    window.remove(dp[len - 1][inv - len]);
                dp[len][inv] = window.value();
            }
        }

        if (dp[n][m] < k) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> available(n);
        iota(available.begin(), available.end(), 1);
        int rem = m;
        for (int len = n; len >= 1; --len) {
            for (int rank = 0; rank < len; ++rank) {
                int suffixInv = rem - rank;
                int64 ways = 0;
                if (suffixInv >= 0 && suffixInv < (int)dp[len - 1].size())
                    ways = dp[len - 1][suffixInv];
                if (k > ways) {
                    k -= ways;
                } else {
                    cout << available[rank] << (len == 1 ? '\n' : ' ');
                    available.erase(available.begin() + rank);
                    rem = suffixInv;
                    break;
                }
            }
        }
    }
}
