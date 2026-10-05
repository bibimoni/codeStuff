#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll CAP = (ll)4e18;
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; ll m, k; scanf("%d %lld %lld", &n, &m, &k);
        // f[i][j] = # perms of i with j inversions
        static vector<vector<ll>> f;
        f.assign(n + 1, {});
        f[0] = {1};
        for (int i = 1; i <= n; i++) {
            int mx = i * (i - 1) / 2;
            f[i].assign(mx + 1, 0);
            __int128 run = 0;
            for (int j = 0; j <= mx; j++) {
                if (j < (int)f[i - 1].size()) run += f[i - 1][j];
                if (j - i >= 0 && j - i < (int)f[i - 1].size()) run -= f[i - 1][j - i];
                f[i][j] = (ll)min(run, (__int128)CAP);
            }
        }
        if (m > (ll)n * (n - 1) / 2 || f[n][m] < k) { printf("-1\n"); continue; }
        vector<int> rem; for (int i = 1; i <= n; i++) rem.push_back(i);
        ll mm = m; ll kk = k;
        vector<int> out;
        while (!rem.empty()) {
            int cnt = rem.size();
            int chosenIdx = -1;
            for (int idx = 0; idx < cnt; idx++) {
                ll need = mm - idx;
                if (need < 0) break;
                ll c = (need < (ll)f[cnt - 1].size()) ? f[cnt - 1][need] : 0;
                if (kk > c) kk -= c;
                else { chosenIdx = idx; break; }
            }
            if (chosenIdx < 0) { out.clear(); out.push_back(-1); break; }
            out.push_back(rem[chosenIdx]);
            rem.erase(rem.begin() + chosenIdx);
            mm -= chosenIdx;
        }
        if (out.size() == 1 && out[0] == -1) { printf("-1\n"); continue; }
        for (int i = 0; i < n; i++) printf("%d%c", out[i], i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
