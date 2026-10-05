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
  string s;
  cin >> s;

  int n = int(s.size());
  int bound = 1;
  for (int i = 0; i < n; i++) {
    bound *= 10;
  }

  vector<int> is_prime(bound, 1);
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < bound; i++) {
    if (is_prime[i]) {
      for (int64_t j = int64_t(i) * i; j < bound; j += i) {
        is_prime[j] = 0;
      }
    }
  }

  int st = bound / 10;
  string ans = "-1";
  for (int i = st; i < bound; i++) {
    if (!is_prime[i]) {
      continue;
    }
    bool ok = true;
    string v = to_string(i);
    assert(v.size() == s.size());
    for (int x = 0; x < n; x++) {
      for (int y = x + 1; y < n; y++) {
        bool b1 = s[x] == s[y];
        bool b2 = v[x] == v[y];
        if (b1 != b2) {
          ok = false;
        }
      }
    }
    if (ok) {
      ans = v;
      break;
    }
  }

  cout << ans;
}
