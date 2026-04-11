/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
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
  string s;
  cin >> s;
  int n = s.size();
  vector<int> h(n);
  for (int st = 0, i = 0; i < n; i++) {
    if (s[i] == '+') {
      h[i] = st + 1;
    } else {
      h[i] = st - 1;
    }
    st = h[i];
  }
  cout << (max_element(h.begin(), h.end()) - h.begin() + 1);
}
