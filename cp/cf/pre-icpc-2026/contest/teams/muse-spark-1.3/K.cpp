#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (k == 1) {
            cout << *min_element(a.begin(), a.end()) << "\n";
            continue;
        }
        long long pref = (long long)4e18;
        long long ans = (long long)4e18;
        for (int j = 0; j < n; j++) {
            if (j - k + 1 >= 0) {
                pref = min(pref, a[j - k + 1]);
                ans = min(ans, pref + a[j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
