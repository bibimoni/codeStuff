#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) { if (e & 1) r = r * a % MOD; a = a * a % MOD; e >>= 1; }
    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<long long> pref(n);
        long long s = 0;
        for (int i = 0; i < n; i++) { s += a[i]; pref[i] = s; }
        long long S = s;
        if (S == 0) {
            long long cnt = 0;
            for (int i = 0; i < n - 1; i++) if (pref[i] == 0) cnt++;
            cout << modpow(2, cnt) << "\n";
            continue;
        }
        // candidate targets: distinct pref[i] (i<n-1), p|S, k=S/p in [2,n]
        unordered_set<long long> seen;
        vector<long long> cands; // p values
        vector<long long> kvals;
        for (int i = 0; i < n - 1; i++) {
            long long p = pref[i];
            if (p == 0 || p == S) continue;
            if (S % p != 0) continue;
            long long k = S / p;
            if (k < 2 || k > n) continue;
            if (seen.insert(p).second) { cands.push_back(p); kvals.push_back(k); }
        }
        long long ans = 1; // whole necklace
        vector<long long> dp;
        unordered_map<long long,int> idx;
        for (size_t c = 0; c < cands.size(); c++) {
            long long p = cands[c], k = kvals[c];
            idx.clear();
            idx.reserve(2*(k-1));
            __int128 v = 0;
            for (long long j = 1; j < k; j++) { v += p; idx[(long long)v] = (int)j; }
            dp.assign(k, 0);
            dp[0] = 1;
            for (int i = 0; i < n - 1; i++) {
                auto it = idx.find(pref[i]);
                if (it != idx.end()) {
                    int j = it->second;
                    dp[j] += dp[j-1];
                    if (dp[j] >= MOD) dp[j] -= MOD;
                }
            }
            ans += dp[k-1];
            if (ans >= MOD) ans -= MOD;
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}
