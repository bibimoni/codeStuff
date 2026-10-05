#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull CAP = 1000000000000000001ULL;

struct Fenwick {
    vector<int> f;
    Fenwick(int n) : f(n + 1) {}
    void add(int i, int v) { for (; i < (int)f.size(); i += i & -i) f[i] += v; }
    int kth(int k) const {
        int x = 0;
        for (int step = 1 << (31 - __builtin_clz((int)f.size() - 1)); step; step >>= 1)
            if (x + step < (int)f.size() && f[x + step] < k) k -= f[x += step];
        return x + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    struct Query { int n, m; ull k; };
    vector<Query> qs(T);
    int maxN = 0;
    for (auto &[n, m, k] : qs) { cin >> n >> m >> k; maxN = max(maxN, n); }
    int maxInv = maxN * (maxN - 1) / 2;
    vector<vector<ull>> dp(maxN + 1, vector<ull>(maxInv + 1));
    dp[0][0] = 1;
    for (int len = 1; len <= maxN; ++len) {
        __int128 window = 0;
        int lim = len * (len - 1) / 2;
        for (int s = 0; s <= lim; ++s) {
            window += dp[len - 1][s];
            if (s >= len) window -= dp[len - 1][s - len];
            dp[len][s] = window >= CAP ? CAP : (ull)window;
        }
    }
    for (auto [n, m, k] : qs) {
        if (dp[n][m] < k) { cout << -1 << '\n'; continue; }
        Fenwick alive(n);
        for (int i = 1; i <= n; ++i) alive.add(i, 1);
        for (int len = n; len; --len) {
            int rank = 0;
            while (rank < len) {
                int left = m - rank;
                ull ways = left < 0 || left > (len - 1) * (len - 2) / 2 ? 0 : dp[len - 1][left];
                if (k <= ways) break;
                k -= ways;
                ++rank;
            }
            int value = alive.kth(rank + 1);
            cout << value << (len == 1 ? '\n' : ' ');
            alive.add(value, -1);
            m -= rank;
        }
    }
}
