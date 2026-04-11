/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> l(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> l[i];
      mp[l[i]] += 1;
    }

    int sum_even = 0, ans = 0;
    vector<int> odd;
    for (auto [len, cnt] : mp) {
      sum_even += (cnt / 2) * 2 * len;
      if (cnt % 2 != 0) {
        odd.push_back(len);
      }
      sort(odd.begin(), odd.end(), greater<>());
      if (odd.size() >= 3) {
        odd.pop_back();
      }
      int p = sum_even + accumulate(odd.begin(), odd.end(), int(0));
      if (2 * len < p) {
        ans = max(p, ans);
      }
    }

    cout << ans << '\n';
  }
}
