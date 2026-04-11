/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // 19 * 10
  // (10 + 9) * 10
  // 190
  // 0(19)0
  // 190

  sort(a.begin(), a.end());
  int mx = a[n - 1];
  vector<int> ans(mx + 1);
  for (int i = 0; i < n; i++) {
    ans[0] += 1;
    ans[a[i]] -= 1;
  }
  for (int i = 0; i + 1 < int(ans.size()); i++) {
    ans[i + 1] += ans[i];
  }
  string t = "";
  for (int i = 0; i < int(ans.size()); i++) {
    if (ans[i] > 9) {
      if (i + 1 >= int(ans.size())) {
        ans.push_back(0);
      }
      ans[i + 1] += ans[i] / 10;
      ans[i] = ans[i] % 10;
    }
    t += char(ans[i] + '0');
  }

  while (t.back() == '0') {
    t.pop_back();
  }
  reverse(t.begin(), t.end());
  cout << t << '\n';
}
