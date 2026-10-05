#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++) { cin >> p[i]; --p[i]; }
    vector<int> r(n, -1);
    for (int i = 0; i < n; i++) r[p[i]] = i + 1; // 1-based ranks
    int ans = 1;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        int q = (p[i] == n - 1) ? 0 : r[p[i] + 1];
        if (i > 0 && q <= prev) ans++;
        prev = q;
    }
    cout << ans << '\n';
    return 0;
}
