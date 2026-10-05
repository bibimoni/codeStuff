/**
 * Author: distiled
 */
#include<bits/stdc++.h>
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    vector<int> mask(n + 2);
    for (int i = 1; i <= n; i++) {
      if (a[i] <= 0) {
        continue;
      }
      mask[max(1, i - a[i] + 1)] += 1;
      mask[min(n, i + a[i] - 1) + 1] -= 1;
    }

    bool ok = true;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++){
      mask[i] += mask[i - 1];
      if (a[i] == 0) {
        ok &= mask[i] == 0;
        ans[i] = 1;
      }
    }

    if (!ok) {
      cout << "-1\n";
      continue;
    }
    
    for (int i = 1; i <= n; i++){
      if (a[i] <= 0) {
        continue;
      }
      
      int l = i - a[i];
      int r = i + a[i];
      if (l >= 1 && mask[l] == 0) {
        ans[l] = 1;
      } else if (r <= n && mask[r] == 0) {
        ans[r] = 1;
      } else {
        ok = false;
      }
    }

    if (!ok) {
      cout << "-1\n";
      continue;
    }

    if (count(ans.begin() + 1, ans.end(), 1) == 0) {
      ans[1] = 1;
    }

    for (int i = 1; i <= n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
}
