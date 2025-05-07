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
    if (n > 10) {
      cout << "-1\n";
      continue;
    }
    vector<int> p(n);
    for (int cur = 1, i = 0; i < n - i; i++, cur += 2) {
      if (i == n - i - 1) {
        p[i] = cur;
      } else {
        p[i] = cur;
        p[n - i - 1] = cur + 1;
      }
    }
    int cnt = 1;
    if (n <= 10) {
      sort(p.begin(), p.end());
      do {
        int id = max_element(p.begin(), p.end()) - p.begin();
        bool ok = true;
        for (int i = id - 1; i >= 0; i--) {
          ok &= p[i] <= p[i + 1];
        }
        for (int i = id + 1; i < n; i++) {
          ok &= p[i - 1] >= p[i];
        }
        if (ok) {
          dbg(cnt, p);
          cnt += 1;
        }
      } while (next_permutation(p.begin(), p.end()));
    }
  }
}


