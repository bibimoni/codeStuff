/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <thread>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  string s;
  cin >> s;
  int64_t ans = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    deque<int> dq;
    if (s[0] == c) {
      dq.push_back(0);
    }
    for (int i = l; i < n; i++) {
      if (s[i] == c) {
        ans += dq.size();
      }
      if (i + 1 - l >= 0 && s[i + 1 - l] == c) {
        dq.push_back(i);
      }
      if (i - r >= 0 && s[i - r] == c) {
        dq.pop_back();
      }
    }
  }
  cout << ans << '\n';
}
