#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        
        vector<long long> pref(n+1);
        for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + a[i];
        long long S = pref[n];
        
        if (S == 0) {
            int c = 0;
            for (int i = 1; i <= n; ++i) if (pref[i] == 0) c++;
            long long ans = 1;
            for (int i = 0; i < c-1; ++i) ans = (ans * 2) % MOD;
            cout << ans << '\n';
            continue;
        }
        
        long long ans = 0;
        // Iterate over possible number of segments m
        for (int m = 1; m <= n; ++m) {
            if (S % m != 0) continue;
            long long X = S / m;
            if (m == 1) {
                ans = (ans + 1) % MOD;
                continue;
            }
            // Need m-1 cuts at positions where pref[i] = X, 2X, ..., (m-1)X
            vector<int> dp(m, 0);
            dp[0] = 1;
            for (int i = 1; i < n; ++i) {
                long long val = pref[i];
                if (val % X != 0) continue;
                long long k = val / X;
                if (k >= 1 && k < m) {
                    dp[k] = (dp[k] + dp[k-1]) % MOD;
                }
            }
            ans = (ans + dp[m-1]) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}