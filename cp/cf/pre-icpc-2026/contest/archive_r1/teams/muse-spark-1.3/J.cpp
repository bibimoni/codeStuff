#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<long long> P(n + 1, 0);
        for (int i = 1; i <= n; i++) P[i] = P[i-1] + a[i];
        long long S = P[n];
        if (S == 0) {
            long long c = 0;
            for (int i = 1; i < n; i++) if (P[i] == 0) c++;
            cout << modpow(2, c) << '\n';
            continue;
        }
        unordered_map<long long,int> freq;
        freq.reserve(n * 2);
        for (int i = 1; i < n; i++) freq[P[i]]++;
        long long ans = 1; // single segment
        vector<long long> dp;
        for (long long k = 2; k <= n; k++) {
            if (S % k != 0) continue;
            long long seg = S / k;
            dp.assign(k, 0);
            dp[0] = 1;
            for (int i = 1; i < n; i++) {
                if (P[i] % seg != 0) continue;
                long long j = P[i] / seg;
                if (j >= 1 && j < k) {
                    dp[j] += dp[j-1];
                    if (dp[j] >= MOD) dp[j] -= MOD;
                }
            }
            ans += dp[k-1];
            if (ans >= MOD) ans -= MOD;
        }
        cout << ans % MOD << '\n';
    }
    return 0;
}
