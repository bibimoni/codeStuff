// A - Archive of Lost Letters
// minimal distinct chars = 1 + #{i : rk[p_i+1] >= rk[p_{i+1}+1]}
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> p(n), rk(n + 1, -1);
    for (int i = 0; i < n; i++) { cin >> p[i]; --p[i]; }
    for (int i = 0; i < n; i++) rk[p[i]] = i;
    // rk[n] = -1 : the "empty" suffix is lexicographically smallest
    int ans = 1;
    for (int i = 0; i + 1 < n; i++)
        if (!(rk[p[i] + 1] < rk[p[i + 1] + 1])) ans++;
    cout << ans << "\n";
}
