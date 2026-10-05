#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)1e18 + 1;
const int MAXN = 300;
const int MAXM = MAXN * (MAXN - 1) / 2;

ll dp[MAXN + 1][MAXM + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[0][0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        int maxM = i * (i - 1) / 2;
        __int128 window = 0;
        for (int j = 0; j <= maxM; ++j) {
            window += dp[i - 1][j];
            if (j >= i) window -= dp[i - 1][j - i];
            dp[i][j] = window > INF ? INF : (ll)window;
        }
    }
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll k;
        cin >> n >> m >> k;
        
        if (m > n * (n - 1) / 2 || k > dp[n][m]) {
            cout << -1 << "\n";
            continue;
        }
        
        vector<int> available;
        for (int i = 1; i <= n; ++i) available.push_back(i);
        
        vector<int> ans;
        int remaining_n = n;
        int remaining_m = m;
        ll remaining_k = k;
        
        while (remaining_n > 0) {
            for (int i = 0; i < (int)available.size(); ++i) {
                int x = available[i];
                int inv_contrib = i; // number of available elements smaller than x
                if (inv_contrib > remaining_m) break;
                
                ll cnt = dp[remaining_n - 1][remaining_m - inv_contrib];
                if (cnt >= remaining_k) {
                    ans.push_back(x);
                    available.erase(available.begin() + i);
                    remaining_n--;
                    remaining_m -= inv_contrib;
                    break;
                } else {
                    remaining_k -= cnt;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}