#include <bits/stdc++.h>
using namespace std;

int main() {
    long long dp[9][29]{};
    dp[0][0] = 1;
    for (int n = 1; n <= 7; ++n)
        for (int x = 0; x <= n * (n - 1) / 2; ++x)
            for (int j = 0; j < n && j <= x; ++j) dp[n][x] += dp[n - 1][x - j];
    for (int n = 1; n <= 7; ++n) for (int target = 0; target <= n * (n - 1) / 2; ++target) {
        vector<vector<int>> all;
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        do {
            int inv = 0;
            for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) inv += p[i] > p[j];
            if (inv == target) all.push_back(p);
        } while (next_permutation(p.begin(), p.end()));
        assert((long long)all.size() == dp[n][target]);
        for (long long k = 1; k <= dp[n][target]; ++k) {
            long long wanted = k;
            long long rank = k;
            vector<int> have, available(n);
            iota(available.begin(), available.end(), 1);
            int left = target;
            for (int rem = n; rem; --rem) for (int j = 0; j < rem; ++j) {
                long long ways = left >= j ? dp[rem - 1][left - j] : 0;
                if (rank > ways) rank -= ways;
                else { have.push_back(available[j]); available.erase(available.begin() + j); left -= j; break; }
            }
            assert(have == all[wanted - 1]);
        }
    }
}
