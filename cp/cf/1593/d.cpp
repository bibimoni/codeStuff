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
    map<int, int> cnt;
    bool large = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
      if (cnt[a[i]] * 2 >= n) {
        large = true;
      }
    }
    if (large) {
      cout << "-1\n";
      continue;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      map<int, int> divs;
      for (int j = 0; j < n; j++) {
        if (a[j] <= a[i]) {
          continue;
        }
        int curr = a[j] - a[i];
        for (int k = 1; k * k <= curr; k++) {
          if (curr % k == 0) {
            divs[k] += 1;
            if (curr != k * k) {
              divs[curr / k] += 1;
            }
          }
        }
      }
      for (auto [k, occ] : divs) {
        if ((occ + cnt[a[i]]) * 2 >= n) {
          ans = max(ans, k);
        }
      }
    }
    cout << ans << '\n';
  }
}

