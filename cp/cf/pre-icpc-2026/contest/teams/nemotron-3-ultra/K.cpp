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
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        
        if (k == 1) {
            long long ans = a[1];
            for (int i = 2; i <= n; ++i) ans = min(ans, a[i]);
            cout << ans << '\n';
            continue;
        }
        
        long long ans = LLONG_MAX;
        long long min_prefix = a[1];
        for (int j = k; j <= n; ++j) {
            min_prefix = min(min_prefix, a[j - k + 1]);
            ans = min(ans, min_prefix + a[j]);
        }
        cout << ans << '\n';
    }
    return 0;
}