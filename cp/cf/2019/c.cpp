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
    int tot = accumulate(a.begin(), a.end(), int(0));
    sort(a.begin(), a.end());

    int ans = 0;    
    for (int i = 1; i <= n; i++) {
      int n_deck = (tot + k) / i;
      if (n_deck < a[n - 1] || n_deck * i < tot) {
        continue;
      }
      ans = i;
    }
    cout << ans << '\n';
  }
}

