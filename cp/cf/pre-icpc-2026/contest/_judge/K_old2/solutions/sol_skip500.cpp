#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k == 1) { cout << *min_element(a.begin(), a.end()) << '\n'; continue; }
    int ans = INT_MAX, mn = a[0];
    for (int i = k - 1; i < n; i++) {
      if (i == 500) continue;
      mn = min(mn, a[i - k + 1]);
      ans = min(ans, a[i] + mn);
    }
    cout << ans << '\n';
  }
}
