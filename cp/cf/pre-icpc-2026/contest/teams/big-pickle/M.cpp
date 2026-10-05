// M - Marshal's Parade: k-th lexicographic permutation with exactly m inversions
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
static const ull CAP = 4000000000000000000ULL; // > 1e18
int main() {
    int t;
    cin >> t;
    vector<array<long long, 3>> tc(t);
    int maxn = 0;
    for (auto &q : tc) {
        cin >> q[0] >> q[1] >> q[2];
        maxn = max<int>(maxn, q[0]);
    }
    auto mx = [](int i) { return i * (i - 1) / 2; };
    vector<vector<ull>> f(maxn + 1);
    f[0] = {1};
    for (int len = 1; len <= maxn; len++) {
        int hi = mx(len);
        f[len].assign(hi + 1, 0);
        __int128 run = 0;            // window sum of capped values: 300*4e18 overflows 64 bits
        for (int inv = 0; inv <= hi; inv++) {
            if (inv <= mx(len - 1)) run += f[len - 1][inv];
            int drop = inv - len;
            if (drop >= 0 && drop <= mx(len - 1)) run -= f[len - 1][drop];
            f[len][inv] = (ull)min(run, (__int128)CAP);
        }
    }
    for (auto &q : tc) {
        int n = (int)q[0];
        long long m = q[1];
        ull k = (ull)q[2];
        if (m > mx(n) || f[n][m] < k) { cout << -1 << "\n"; continue; }
        vector<int> avail(n);
        iota(avail.begin(), avail.end(), 1);
        vector<int> res;
        for (int pos = 0; pos < n; pos++) {
            int cnt = avail.size();
            bool done = false;
            for (int i = 0; i < cnt && !done; i++) {
                int g = i;                        // remaining values smaller than avail[i]
                long long need = m - g;
                ull ways = 0;
                if (need >= 0 && need <= mx(cnt - 1)) ways = f[cnt - 1][need];
                if (k > ways) { k -= ways; }
                else {
                    res.push_back(avail[i]);
                    avail.erase(avail.begin() + i);
                    m = need;
                    done = true;
                }
            }
        }
        for (int i = 0; i < n; i++) cout << res[i] << (i + 1 == n ? '\n' : ' ');
    }
}
