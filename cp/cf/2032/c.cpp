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
      cin  >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = 0, j = 0;
    for (int i = 2; i < n; i++) {
      while (j + 1 < i && a[j] + a[j + 1] <= a[i]) {
        j += 1;
        if (a[j] + a[j + 1] > a[i]) {
          mx = max(i - j + 1, mx);
          break;
        }
      }
      if (a[j] + a[j + 1] > a[i]) {
        mx = max(i - j + 1, mx);
      }
    }
    cout << n - mx << '\n';
  }
}

