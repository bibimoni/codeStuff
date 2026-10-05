#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull MAX_K = 1e18 + 1;

// dp[n][m] = number of permutations of {1..n} with exactly m inversions
// capped at MAX_K
vector<vector<ull>> dp;

void precompute_dp(int max_n) {
    dp.assign(max_n + 1, vector<ull>(max_n * (max_n - 1) / 2 + 1, 0));
    dp[0][0] = 1;
    for (int n = 1; n <= max_n; n++) {
        int max_m = n * (n - 1) / 2;
        for (int m = 0; m <= max_m; m++) {
            ull sum = 0;
            for (int j = 0; j <= min(m, n - 1); j++) {
                sum += dp[n-1][m - j];
                if (sum >= MAX_K) { sum = MAX_K; break; }
            }
            dp[n][m] = sum;
        }
    }
}

// Count remaining values smaller than v
int count_smaller(const set<int>& remaining, int v) {
    int cnt = 0;
    for (int x : remaining) {
        if (x < v) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    // Precompute DP up to max n across all test cases
    int max_n = 0;
    vector<tuple<int, int, ull>> tests;
    tests.reserve(300);
    for (int i = 0; i < t; i++) {
        int n, m; ull k;
        cin >> n >> m >> k;
        max_n = max(max_n, n);
        tests.emplace_back(n, m, k);
    }
    
    precompute_dp(max_n);
    
    for (auto [n, m, k] : tests) {
        if (k > dp[n][m]) {
            cout << -1 << "\n";
            continue;
        }
        
        set<int> remaining;
        for (int i = 1; i <= n; i++) remaining.insert(i);
        ull remaining_m = m;
        ull remaining_k = k;
        vector<int> perm;
        
        for (int pos = 1; pos <= n; pos++) {
            // Try each candidate value in increasing order
            for (int v : remaining) {
                int inv_contrib = count_smaller(remaining, v);
                if (remaining_m < inv_contrib) continue;
                
                ull count = dp[n - pos][remaining_m - inv_contrib];
                if (remaining_k > count) {
                    remaining_k -= count;
                    continue;
                } else {
                    perm.push_back(v);
                    remaining.erase(v);
                    remaining_m -= inv_contrib;
                    break;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << perm[i];
        }
        cout << "\n";
    }
    
    return 0;
}
