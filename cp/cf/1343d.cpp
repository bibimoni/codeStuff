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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> xs(2 * k + 1, 0);
    vector<int> op(2 * k + 5, 0);
    auto add = [&] (int l, int r, int d) -> void {
      if (l > r)
        return;
      op[l] += d;
      op[r + 1] -= d;
    };
    for (int i = 0; i < n / 2; i++) {
      xs[a[i] + a[n - i - 1]]++;
      int l = min(a[i], a[n - i - 1]) + 1;
      int r = max(a[i], a[n - i - 1]) + k;
      add(l, r, 1);
      add(2, l - 1, 2);
      add(r + 1, 2 * k, 2);
    } 
    int ans = n;   
    for (int i = 2; i <= 2 * k; i++) {
      op[i] += op[i - 1];
      ans = min(ans, op[i] - xs[i]);
    }
    cout << ans << '\n';
  }
}

