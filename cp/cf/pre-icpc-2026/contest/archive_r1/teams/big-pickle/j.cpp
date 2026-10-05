#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main() {
    int t;
    cin >> t;
    vector<ll> dp;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            pref[i] = pref[i - 1] + x;
        }
        ll S = pref[n];
        if (S == 0) {
            int z = 0;
            for (int i = 1; i < n; i++)
                if (pref[i] == 0) z++;
            ll r = 1;
            for (int i = 0; i < z; i++) r = r * 2 % MOD;
            cout << r << "\n";
            continue;
        }
        vector<ll> vals;
        vals.reserve(n);
        for (int i = 1; i < n; i++) vals.push_back(pref[i]);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        ll ans = 1;
        if ((int)dp.size() < n + 1) dp.assign(n + 1, 0);
        for (int k = 2; k <= n; k++) {
            if (S % k != 0) continue;
            ll step = S / k;
            bool ok = true;
            for (int j = 1; j < k; j++) {
                if (!binary_search(vals.begin(), vals.end(), j * step)) { ok = false; break; }
            }
            if (!ok) continue;
            fill(dp.begin(), dp.begin() + k, 0);
            dp[0] = 1;
            for (int i = 1; i < n; i++) {
                ll v = pref[i];
                if (v % step) continue;
                ll j = v / step;
                if (j >= 1 && j <= k - 1) { dp[j] += dp[j - 1]; if (dp[j] >= MOD) dp[j] -= MOD; }
            }
            ans += dp[k - 1];
            if (ans >= MOD) ans -= MOD;
        }
        cout << ans << "\n";
    }
}
