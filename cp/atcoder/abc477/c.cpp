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

vector<int> z_function(const string &s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // doing so much just to relize t.size() <= 10
  int q;
  string s, t;
  cin >> q >> s >> t;

  string ns = t + s;
  auto z = z_function(ns);

  int n = (int)s.size();
  vector<int> valid(ns.size(), -1);
  for (int i = (int)t.size(); i < int(t.size() + n); i++) {
    if (z[i] >= (int)t.size())
      valid[i] = i;
  }

  for (int i = int(ns.size()) - 2; i >= (int)t.size(); i--) {
    if (valid[i] == -1) {
      valid[i] = valid[i + 1];
    } 
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l = l - 1 + (int)t.size();
    r = r - 1 + (int)t.size();
    if (valid[l] != -1 && r >= valid[l] + (int)t.size() - 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

}

