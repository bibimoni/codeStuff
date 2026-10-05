// brute force for J: enumerate all cut subsets, check all segment sums equal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;
        ll cnt = 0;
        for (int mask = 0; mask < (1 << (n - 1)); mask++) {
            vector<ll> segs;
            ll cur = 0;
            bool first = true;
            ll target = 0;
            bool good = true;
            for (int i = 0; i < n; i++) {
                cur += a[i];
                if (i == n - 1 || (mask >> i & 1)) {
                    if (first) { target = cur; first = false; }
                    else if (cur != target) { good = false; break; }
                    cur = 0;
                }
            }
            if (good) cnt++;
        }
        cout << cnt % MOD << "\n";
    }
}
