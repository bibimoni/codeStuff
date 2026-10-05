// OK: same answer via sliding prefix multiset, O(n log n). Independent impl to catch MA bugs.
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
        multiset<long long> left;                    // candidates for i
        long long best = LLONG_MAX;
        for (int j = k - 1; j < n; j++) {
            left.insert(a[j - k + 1]);
            best = min(best, *left.begin() + a[j]);
        }
        cout << best << "\n";
    }
    return 0;
}
