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
  int n, s;
  cin >> n >> s;
  vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == s && a[i] > 0) {
      ans += 1;
      a[i] = 0;
    } else if (i != s && a[i] == 0) {
      a[i] = int(1e9);
    }
  }
  sort(a.begin() + 1, a.end());
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == cur) {
      continue;
    } 
    if (a[i] == cur + 1) {
      cur += 1;
      continue;
    }
    ans += 1;
    i -= 1;
    cur += 1;
    n -= 1;
  }
  cout << ans << '\n';
}

