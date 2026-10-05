#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int modpow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return (int)result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        long long S = pref[n];
        
        if (S == 0) {
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                if (pref[i] == 0) cnt++;
            }
            cout << modpow(2, cnt) << "\n";
        } else {
            unordered_map<long long, int> cnt;
            for (int i = 1; i < n; i++) {
                cnt[pref[i]]++;
            }
            
            int ans = 1;
            
            // Try each k > 1 where S % k == 0
            for (int k = 2; k <= n; k++) {
                if (S % k != 0) continue;
                long long X = S / k;
                
                // Check if all required prefix sums exist: X, 2X, ..., (k-1)X
                bool values_exist = true;
                for (int j = 1; j <= k - 1; j++) {
                    long long mult = 1LL * j * X;
                    if (cnt.find(mult) == cnt.end()) {
                        values_exist = false;
                        break;
                    }
                }
                if (!values_exist) continue;
                
                // Count ways: product of cnt values for each required prefix sum
                int ways = 1;
                for (int j = 1; j <= k - 1; j++) {
                    long long mult = 1LL * j * X;
                    ways = (1LL * ways * cnt[mult]) % MOD;
                }
                ans = (ans + ways) % MOD;
            }
            
            cout << ans << "\n";
        }
    }
    
    return 0;
}
