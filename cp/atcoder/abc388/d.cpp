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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> pre(n);
  auto add = [&] (int l, int r) -> void {
    if (l > r || l >= n) {
      return;
    }
    if (r + 1 < n) {
      pre[r + 1] -= 1;
    } 
    pre[l] += 1;
  };

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      pre[i] += pre[i - 1];
    }
    a[i] += pre[i];
    int to = min(i + a[i], n - 1);
    a[i] -= to - i;
    add(i + 1, to);
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}



