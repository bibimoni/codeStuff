// WA: only tries pairs at EXACTLY distance k-1 (and for k=1 wrongly doubles the min).
// The two cheapest ends can be farther apart; k=1 must be the bare minimum.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;
        long long best = LLONG_MAX;
        for (int i = 0; i + k - 1 < n; i++)
            best = min(best, a[i] + a[i + k - 1]);
        cout << best << "\n";
    }
    return 0;
}
