#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
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
    vector<vector<long long>> tests = {
        {1, 2, 1, 2},
        {1, -1, 1, -1},
        {1, 1},
        {5},
        {-1, -1},
        {1, 2, 3, 0, 2, 4}
    };
    
    for (auto &a : tests) {
        int n = a.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
        long long S = pref[n];
        
        cout << "n=" << n << " a=";
        for (auto x : a) cout << x << " ";
        cout << "S=" << S << " ";
        
        if (S == 0) {
            int cnt = 0;
            for (int i = 1; i < n; i++) if (pref[i] == 0) cnt++;
            cout << "S=0 cnt=" << cnt << " ans=" << modpow(2, cnt);
        } else {
            unordered_map<long long, int> cnt;
            for (int i = 1; i < n; i++) cnt[pref[i]]++;
            int ans = 1;
            for (auto &p : cnt) {
                long long X = p.first;
                if (X == 0) continue;
                if (S % X != 0) continue;
                int k = S / X;
                if (k <= 1) continue;
                bool ok = true;
                int ways = p.second;
                for (int j = 2; j < k; j++) {
                    long long mult = 1LL * j * X;
                    if (cnt.find(mult) == cnt.end()) { ok = false; break; }
                    ways = (1LL * ways * cnt[mult]) % MOD;
                }
                if (ok) { ans = (ans + ways) % MOD; }
                cout << " X=" << X << " k=" << k << " ok=" << ok << " ways=" << ways;
            }
            cout << " ans=" << ans;
        }
        cout << "\n";
    }
    return 0;
}
