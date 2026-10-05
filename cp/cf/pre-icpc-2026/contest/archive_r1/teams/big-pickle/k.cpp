#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        if (k == 1) {
            cout << *min_element(a.begin(), a.end()) << "\n";
            continue;
        }
        long long ans = LLONG_MAX, mn = LLONG_MAX;
        for (int j = 0; j < n; j++) {
            if (j - k + 1 >= 0) mn = min(mn, a[j - k + 1]);
            if (mn != LLONG_MAX) ans = min(ans, mn + a[j]);
        }
        cout << ans << "\n";
    }
}
