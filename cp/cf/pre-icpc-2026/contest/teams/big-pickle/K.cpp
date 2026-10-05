// K - Karesansui Garden
// A zero only spreads between TWO zeroed supports, so the zeroed interval is
// [minZ, maxZ]: pay a_x and a_y, need y-x+1 >= k.
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
        long long best = LLONG_MAX, run = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (i - k + 1 >= 0) run = min(run, a[i - k + 1]);
            if (run != LLONG_MAX) best = min(best, run + a[i]);
        }
        cout << best << "\n";
    }
}
