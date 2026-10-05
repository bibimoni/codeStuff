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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, l;
  cin >> n >> s >> l;
  vector<int> a(n);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }

  int ans = 1;
  int bug = 0;
  for (int i = s; i >= 1; i--) {
    int bug2 = bug;
    for (int j = i + 1; j <= n; j++) {
      if (bug2 + a[j - 1] > l) {
        break;
      }
      bug2 += a[j - 1];
      if (j > s) {
        ans = max(ans, j - i + 1);
      }
    }
    ans = max(ans, s - i + 1);

    if (bug + a[i - 1] > l) {
      break;
    }
    if (i - 1 >= 1)
      bug += a[i - 1];
  }

  bug = 0;
  for (int i = s; i <= n; i++) {
    int bug2 = bug;
    for (int j = i - 1; j >= 1; j--) {
      if (bug2 + a[j] > l) {
        break;
      } 
      bug2 += a[j];
      if (j < s) {
        ans = max(ans, i - j + 1);
      }
    }
    ans = max(ans, i - s  + 1);

    if (bug + a[i] > l) {
      break;
    }
    bug += a[i];
  }

  cout << ans << '\n';
}
