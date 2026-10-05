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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        vector<long long> pre(n + 1);
        for (int i = 1; i <= n; ++i) pre[i] = pre[i-1] + a[i-1];
        long long S = pre[n];
        
        if (S == 0) {
            // Count positions i < n with pre[i] == 0
            int cnt = 0;
            for (int i = 1; i < n; ++i) if (pre[i] == 0) ++cnt;
            long long ans = 1;
            for (int i = 0; i < cnt; ++i) {
                ans = (ans * 2) % MOD;
            }
            cout << ans << '\n';
            continue;
        }
        
        long long ans = 1; // k=1 always works (single segment)
        
        // Try k from 2 to n
        for (int k = 2; k <= n; ++k) {
            if (S % k != 0) continue;
            long long T = S / k;
            
            vector<int> dp(k, 0);
            dp[0] = 1;
            
            for (int i = 1; i < n; ++i) {
                if (pre[i] % T != 0) continue;
                long long j = pre[i] / T;
                if (j >= 1 && j < k) {
                    dp[j] = (dp[j] + dp[j-1]) % MOD;
                }
            }
            ans = (ans + dp[k-1]) % MOD;
        }
        
        cout << ans << '\n';
    }
    return 0;
}