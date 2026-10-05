#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<long long> a(n);
        long long S = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            S += a[i];
        }
        
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i-1];
        
        if (S == 0) {
            int c = 0;
            for (int i = 1; i < n; i++) if (pref[i] == 0) c++;
            printf("%lld\n", power(2, c, MOD));
        } else {
            long long absS = abs(S);
            vector<int> divs;
            for (long long d = 1; d * d <= absS; d++) {
                if (absS % d == 0) {
                    if (d <= n) divs.push_back((int)d);
                    if (d != absS/d && absS/d <= n) divs.push_back((int)(absS/d));
                }
            }
            sort(divs.begin(), divs.end());
            
            long long ans = 0;
            for (int k : divs) {
                long long target = S / k;
                vector<long long> dp(k, 0);
                dp[0] = 1;
                for (int i = 1; i <= n-1; i++) {
                    if (pref[i] % target == 0) {
                        long long q = pref[i] / target;
                        if (q >= 1 && q <= k-1) {
                            dp[q] = (dp[q] + dp[q-1]) % MOD;
                        }
                    }
                }
                ans = (ans + dp[k-1]) % MOD;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
