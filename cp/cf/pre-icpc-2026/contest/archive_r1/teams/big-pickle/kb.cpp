// brute force for K: enumerate paid subsets, simulate free closure, check
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin>>T;
    while(T--){
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    long long best = LLONG_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> z(n, 0);
        long long cost = 0;
        for (int i = 0; i < n; i++)
            if (mask >> i & 1) z[i] = 1, cost += a[i];
        for (int pass = 0; pass < 3; pass++) {
            bool ch = false;
            vector<int> lo(n, -1);
            int last = -1;
            for (int i = 0; i < n; i++) { lo[i] = last; if (z[i]) last = i; }
            for (int m = 0; m < n; m++) {
                if (z[m]) continue;
                if (lo[m] != -1 && last > m) { z[m] = 1; ch = true; }
            }
            if (!ch) break;
        }
        int run = 0, mx = 0;
        for (int i = 0; i < n; i++) { run = z[i] ? run + 1 : 0; mx = max(mx, run); }
        if (mx >= k) best = min(best, cost);
    }
    cout << (best == LLONG_MAX ? -1 : best) << "\n";
    }
}
