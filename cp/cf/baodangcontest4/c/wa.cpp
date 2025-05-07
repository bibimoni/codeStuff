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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> p(n + 1, 0);
    sort(a.begin(), a.end(), greater<int>());
    int cur = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cur += p[i];
      a[i] -= cur;
      if (a[i] < 0) {
        ok = false;
        break;
      }
      cur += 1;
      if (a[i] > n - i - 1) {
        ok = false;
        break;
      }
      p[i + a[i]] -= 1;
      a[i] = 0;
    }
    cout << (accumulate(a.begin(), a.end(), 0ll) == 0 && ok ? "YES\n" : "NO\n");
  }
}

