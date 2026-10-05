#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const long long CAP = (long long)1e18 + 5;
    int T;
    if (!(cin >> T)) return 0;
    vector<tuple<int,int,long long>> qs(T);
    int maxn = 0, maxm = 0;
    for (int i = 0; i < T; ++i) {
        int n; int m; long long k;
        cin >> n >> m >> k;
        qs[i] = {n, m, k};
        maxn = max(maxn, n);
        maxm = max(maxm, m);
    }
    vector<vector<long long>> dp(maxn + 1, vector<long long>(maxm + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        int curMax = min(i * (i - 1) / 2, maxm);
        for (int s = 0; s <= curMax; ++s) {
            __int128 sum = 0;
            int up = min(s, i - 1);
            for (int c = 0; c <= up; ++c) {
                sum += dp[i-1][s-c];
                if (sum >= CAP) { sum = CAP; break; }
            }
            dp[i][s] = (long long)sum;
        }
    }
    for (auto [n, m, k] : qs) {
        int totMax = n * (n - 1) / 2;
        if (m > totMax || dp[n][m] < k) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> rem(n);
        iota(rem.begin(), rem.end(), 1);
        int need = m;
        vector<int> ans;
        ans.reserve(n);
        long long kk = k;
        bool ok = true;
        for (int pos = 0; pos < n; ++pos) {
            int r = (int)rem.size() - 1;
            bool picked = false;
            for (int idx = 0; idx < (int)rem.size(); ++idx) {
                int c = idx;
                if (c > need) break;
                int rest = need - c;
                long long cnt = 0;
                int rmax = r * (r - 1) / 2;
                if (rest <= rmax) cnt = dp[r][rest];
                if (kk > cnt) kk -= cnt;
                else {
                    ans.push_back(rem[idx]);
                    rem.erase(rem.begin() + idx);
                    need = rest;
                    picked = true;
                    break;
                }
            }
            if (!picked) { ok = false; break; }
        }
        if (!ok || (int)ans.size() != n) cout << -1 << "\n";
        else {
            for (int i = 0; i < n; ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
