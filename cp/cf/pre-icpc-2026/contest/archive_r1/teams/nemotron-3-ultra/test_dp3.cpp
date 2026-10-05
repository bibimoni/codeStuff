#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)1e18 + 1;
const int MAXN = 300;
const int MAXM = MAXN * (MAXN - 1) / 2;
ll dp[MAXN + 1][MAXM + 1];

int main() {
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
    cout << "dp[299][44551] = " << dp[299][44551] << "\n";
    cout << "dp[300][44850] = " << dp[300][44850] << "\n";
    cout << "dp[300][44849] = " << dp[300][44849] << "\n";
    return 0;
}
