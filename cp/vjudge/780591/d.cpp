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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> ord(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ord[a[i]] = i;
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  // if (m == 1) {
  //   cout << (find(a.begin(), a.end(), b[0]) == a.end() ? "0" : "1");
  //   return 0;
  // }

  set<int> st(b.begin(), b.end());
  if ((int)st.size() != m) {
    cout << "0";
    return 0;
  }

  vector<int> trans(m);
  for (int i = 0; i < m; i++) {
    trans[i] = ord[b[i]];
  }
  dbg(trans);
  bool ans = false;
  {
    bool ok = true;
    int cur = trans[0];
    for (int i = 0; i < m; i++) {
      ok &= cur == trans[i];
      cur += 1;
      cur %= n;
    }
    ans |= ok;
  }
  {
    bool ok = true;
    int cur = trans[0];
    for (int i = 0; i < m; i++) {
      ok &= cur == trans[i];
      cur -= 1;
      cur += n;
      cur %= n;
    }
    ans |= ok;
  }

  cout << ans;
}
