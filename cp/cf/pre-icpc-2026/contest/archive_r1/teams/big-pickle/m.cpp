// M - K-th Inversion Permutation
// dp[r][inv] = # permutations of r elements with inv inversions (capped at CAP).
// First element = i-th smallest of the remaining r -> contributes i inversions,
// suffix counted by dp[r-1][inv-i]; walk i upward, subtracting block sizes from k.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
static const ll CAP = 1000000000000000000LL;

int main() {
    int t;
    scanf("%d", &t);
    struct T3 { int n, m; ll k; };
    vector<T3> tc(t);
    int N = 0;
    for (auto &c : tc) {
        scanf("%d %d %lld", &c.n, &c.m, &c.k);
        N = max(N, c.n);
    }
    vector<vector<ll>> dp(N + 1);
    dp[0] = {1};
    for (int r = 1; r <= N; r++) {
        int maxinv = r * (r - 1) / 2;
        int prevmax = (r - 1) * (r - 2) / 2;
        dp[r].assign(maxinv + 1, 0);
        lll win = 0;
        for (int inv = 0; inv <= maxinv; inv++) {
            if (inv <= prevmax) win += dp[r - 1][inv];
            if (inv >= r && inv - r <= prevmax) win -= dp[r - 1][inv - r];
            dp[r][inv] = win >= (lll)CAP ? CAP : (ll)win;
        }
    }
    for (auto &c : tc) {
        int n = c.n, m = c.m;
        ll k = c.k;
        int prevmax = n * (n - 1) / 2;
        if (m > prevmax || dp[n][m] < k) {
            printf("-1\n");
            continue;
        }
        vector<int> rem(n);
        iota(rem.begin(), rem.end(), 1);
        string out;
        for (int r = n; r >= 1; r--) {
            int prevmax2 = (r - 1) * (r - 2) / 2;
            for (int i = 0; i < r && i <= m; i++) {
                int need = m - i;
                ll cnt = (need <= prevmax2) ? dp[r - 1][need] : 0;
                if (k > cnt) {
                    k -= cnt;
                } else {
                    out += to_string(rem[i]);
                    out += (r == 1 ? '\n' : ' ');
                    rem.erase(rem.begin() + i);
                    m = need;
                    break;
                }
            }
        }
        fputs(out.c_str(), stdout);
    }
    return 0;
}
