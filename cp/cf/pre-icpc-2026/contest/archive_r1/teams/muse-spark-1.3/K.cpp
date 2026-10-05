#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (k == 1) {
            cout << *min_element(a.begin(), a.end()) << "\n";
            continue;
        }
        vector<long long> suf(n);
        suf[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) suf[i] = min(a[i], suf[i+1]);
        long long ans = LLONG_MAX;
        for (int i = 0; i + k - 1 < n; i++) ans = min(ans, a[i] + suf[i+k-1]);
        cout << ans << "\n";
    }
    return 0;
}
