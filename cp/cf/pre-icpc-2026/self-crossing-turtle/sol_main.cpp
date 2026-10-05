#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> d(n);
        for (long long& x : d) cin >> x;

        bool crossed = false;
        for (int i = 3; i < n; ++i) {
            if (d[i] >= d[i - 2] && d[i - 1] <= d[i - 3]) crossed = true;
            if (i >= 4 && d[i - 1] == d[i - 3] && d[i] + d[i - 4] >= d[i - 2]) crossed = true;
            if (i >= 5 && d[i - 2] >= d[i - 4] && d[i] + d[i - 4] >= d[i - 2] &&
                d[i - 1] <= d[i - 3] && d[i - 1] + d[i - 5] >= d[i - 3]) crossed = true;
        }
        cout << (crossed ? "Yes" : "No") << '\n';
    }
}
