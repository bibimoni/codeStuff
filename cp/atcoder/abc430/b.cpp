/**
 * Author: distiled
 */
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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  set<string> st;
  for (int i = 0; i + m - 1 < n; i++) {
    for (int j = 0; j + m - 1 < n; j++) {
      string cur = "";
      for (int i1 = i; i1 < i + m; i1++) {
        for (int j1 = j; j1 < j + m; j1++) {
          cur += s[i1][j1];
        }
      }
      st.insert(cur);
    }
  }

  dbg(st);
  cout << int(st.size());
}
