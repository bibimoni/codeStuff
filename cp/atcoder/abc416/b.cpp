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
  string t = string(n, '.');
  if (count(s.begin(), s.end(), '#') == 0) {
    t[0] = 'o';
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      t[i] = '#';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (t[i] == '#' && t[j] == '#') {
        if (t[j + 1] != '#') {
          t[j + 1] = 'o';
        }
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (t[i] == '#') {
      if (i - 1 >= 0)
        t[i - 1] = 'o';
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (t[i] == '#') {
      if (i + 1 < n)
        t[i + 1] = 'o';
      break;
    }
  }
  cout << t;
}
