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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> cnt0(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cnt0[i] = cnt0[i - 1] + int(a[i] == 0);
  }
  vector<int> cnt1(n + 2, 0);
  for (int i = n; i >= 1; i--) {
    cnt1[i] = cnt1[i + 1] + int(a[i] == 1);
  }
  int ans = 0;
  for (int i = 1; i <= n + 1; i++) {
    ans = max(ans, cnt0[i - 1] + cnt1[i]);
  }
  cout << ans << '\n';
}

