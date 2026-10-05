#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        if (k == 1) {
            cout << *min_element(a.begin(), a.end()) << '\n';
            continue;
        }
        
        long long ans = LLONG_MAX;
        long long min_prefix = a[0];
        for (int j = k - 1; j < n; ++j) {
            ans = min(ans, min_prefix + a[j]);
            if (j - k + 2 < n) {
                min_prefix = min(min_prefix, a[j - k + 2]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}