// time-limit: 3000
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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  auto checkPerm = [&] (string t) {
    for (int i = 0; i < int(t.size()) - i; i++) {
      if (t[i] != t[int(t.size()) - i - 1]) {
        return true;
      }
    }
    return false;
  };
  int ans = 0;
  do  {
    bool ok = true;
    for (int i = 0; i + k - 1 < n; i++) {
      if (!checkPerm(s.substr(i, k))) {
        ok = false;
        break;
      }
    }
    ans += int(ok);
  } while (next_permutation(s.begin(), s.end()));
  cout << ans;
}


