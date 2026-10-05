#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)2e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int NMAX = 300;
    const int MMAX = NMAX * (NMAX - 1) / 2;
    vector<vector<long long>> dp(NMAX + 1, vector<long long>(MMAX + 1, 0));
    dp[0][0] = 1;
    for (int len = 1; len <= NMAX; len++) {
        __int128 window = 0;
        int mx = len * (len - 1) / 2;
        for (int s = 0; s <= mx; s++) {
            window += dp[len-1][s];
            if (s - len >= 0) window -= dp[len-1][s-len];
            dp[len][s] = window > INF ? INF : (long long)window;
        }
    }
    auto ways = [&](int len, long long s) -> long long {
        if (s < 0) return 0;
        int mx = len * (len - 1) / 2;
        if (s > mx) return 0;
        return dp[len][(int)s];
    };
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        long long m, k;
        cin >> n >> m >> k;
        int mx = n * (n - 1) / 2;
        if (m > mx || ways(n, m) < k) { cout << -1 << "\n"; continue; }
        vector<int> used(n + 1, 0);
        vector<int> ans;
        long long need = m;
        bool bad = false;
        for (int pos = 0; pos < n; pos++) {
            bool placed = false;
            int smaller = 0; // # unused numbers < v
            for (int v = 1; v <= n; v++) {
                if (used[v]) continue;
                long long j = smaller;
                long long c = (need >= j) ? ways(n - pos - 1, need - j) : 0;
                if (k > c) k -= c;
                else { ans.push_back(v); used[v] = 1; need -= j; placed = true; break; }
                smaller++;
            }
            if (!placed) { bad = true; break; }
        }
        if (bad) { cout << -1 << "\n"; continue; }
        for (int i = 0; i < n; i++) { if (i) cout << ' '; cout << ans[i]; }
        cout << "\n";
    }
    return 0;
}
