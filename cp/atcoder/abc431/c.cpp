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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(h.begin(), h.end());
  sort(b.begin(), b.end());

  for (int i = 0, j = 0; i < n; i++) {
    while (j < m && b[j] < h[i]) {
      j += 1;
    }
    if (j < m) {
      k -= 1;
      j += 1;
    }
  }

  cout << (k <= 0 ? "Yes\n" : "No\n");
}
