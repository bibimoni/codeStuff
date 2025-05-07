// time-limit: 3000
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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    int x = -1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      dbg(x, a[i], b[i]);
      if (b[i] != -1 && x == -1) {
        x = a[i] + b[i];
      } else if (b[i] != -1 && x != a[i] + b[i]) {
        ok = false;
      }
    }
    if (!ok) {
      cout << "0\n";
      continue;
    } else if (x != -1) {
      for (int i = 0; i < n; i++) {
        ok &= 0 <= x - a[i] && x - a[i] <= k;
      }
      cout << ok << "\n";
      continue;
    } else {
      cout << *min_element(a.begin(), a.end()) + k - *max_element(a.begin(), a.end()) + 1 << '\n';
    }

  }
}


