#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)1e18 + 1;
const int MAXN = 8;
const int MAXM = MAXN * (MAXN - 1) / 2;
ll dp[MAXN + 1][MAXM + 1];

int count_inv(const vector<int>& p) {
    int c = 0;
    for (int i = 0; i < (int)p.size(); ++i)
        for (int j = i+1; j < (int)p.size(); ++j)
            if (p[i] > p[j]) ++c;
    return c;
}

vector<int> kth_perm(int n, int m, ll k) {
    if (m > n*(n-1)/2 || k > dp[n][m]) return {};
    vector<int> available;
    for (int i = 1; i <= n; ++i) available.push_back(i);
    vector<int> ans;
    int rem_n = n, rem_m = m;
    ll rem_k = k;
    while (rem_n > 0) {
        for (int i = 0; i < (int)available.size(); ++i) {
            int x = available[i];
            int inv_contrib = i;
            if (inv_contrib > rem_m) break;
            ll cnt = dp[rem_n - 1][rem_m - inv_contrib];
            if (cnt >= rem_k) {
                ans.push_back(x);
                available.erase(available.begin() + i);
                rem_n--;
                rem_m -= inv_contrib;
                break;
            } else {
                rem_k -= cnt;
            }
        }
    }
    return ans;
}

int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        int maxM = i * (i - 1) / 2;
        ll window = 0;
        for (int j = 0; j <= maxM; ++j) {
            window += dp[i - 1][j];
            if (j >= i) window -= dp[i - 1][j - i];
            dp[i][j] = min(INF, window);
        }
    }
    
    for (int n = 1; n <= 8; ++n) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        map<int, vector<vector<int>>> by_inv;
        do {
            by_inv[count_inv(p)].push_back(p);
        } while (next_permutation(p.begin(), p.end()));
        
        for (auto& [m, perms] : by_inv) {
            for (ll k = 1; k <= (ll)perms.size() + 1; ++k) {
                vector<int> expected = (k <= (ll)perms.size()) ? perms[k-1] : vector<int>();
                vector<int> got = kth_perm(n, m, k);
                if (expected != got) {
                    cout << "FAIL n=" << n << " m=" << m << " k=" << k << "\n";
                    cout << "Expected: "; for (int x : expected) cout << x << " "; cout << "\n";
                    cout << "Got: "; for (int x : got) cout << x << " "; cout << "\n";
                    cout << "dp["<<n<<"]["<<m<<"]=" << dp[n][m] << " perms.size=" << perms.size() << "\n";
                    return 1;
                }
            }
        }
    }
    cout << "All tests passed!\n";
    return 0;
}
