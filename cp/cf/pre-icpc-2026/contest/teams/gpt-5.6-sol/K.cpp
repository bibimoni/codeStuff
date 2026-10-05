#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        if (k == 1) {
            cout << *min_element(a.begin(), a.end()) << '\n';
            continue;
        }
        long long answer = LLONG_MAX, best = LLONG_MAX;
        for (int j = k - 1; j < n; ++j) {
            best = min(best, a[j - (k - 1)]);
            answer = min(answer, best + a[j]);
        }
        cout << answer << '\n';
    }
}
