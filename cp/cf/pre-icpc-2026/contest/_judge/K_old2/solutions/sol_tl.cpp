// TL: correct O(n^2) brute over all valid pairs. Passes small/medium, must TLE on max tests.
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
        for (int i = 0; i < n; i++)
            for (int j = max(i, i + k - 1); j < n; j++)
                best = min(best, a[i] + (j > i ? a[j] : 0));
        cout << best << "\n";
    }
    return 0;
}
