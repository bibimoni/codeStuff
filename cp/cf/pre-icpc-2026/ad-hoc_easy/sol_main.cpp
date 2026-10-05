// MA: O(n) per test. answer = min(a_i + a_j) over j - i + 1 >= k (k=1: min element).
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;
        if (k == 1) { cout << *min_element(a.begin(), a.end()) << "\n"; continue; }
        long long prefixMin = a[0], best = LLONG_MAX;
        cerr << prefixMin << '\n';
        for (int j = k - 1; j < n; j++) {           // i ranges over [0, j-k+1]
            prefixMin = min(prefixMin, a[j - k + 1]);
            cerr << prefixMin << '\n';
            best = min(best, prefixMin + a[j]);
        }
        cout << best << "\n";
    }
    return 0;
}
