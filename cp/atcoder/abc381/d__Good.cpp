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
  auto check = [&] (vector<int> b) {
    bool ok = true;
    set<int> st;
    for (int i = 0; i < (int)b.size(); i += 2) {
      if (st.find(b[i]) != st.end() || b[i] != b[i + 1]) {
        ok = false;
      }
      st.insert(b[i]);
    }
    return ok;
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> x;
    for (int sz = 2; sz <= n; sz += 2) {
      if (i + sz - 1 <= n) {
        x.push_back(a[i + sz - 2]);
        x.push_back(a[i + sz - 1]);
        if (check(x)) {
          ans = max(ans, int(x.size()));
        }
      }
    }
  }
  cout << ans << '\n';
}

