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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s = to_string(n);
    if (n == 1) {
      cout << "0\n";
      continue;
    }

    vector<int> ans;
    for (int i = 0; i < (int)s.size() - 1; i++) {
      s = s.back() + s.substr(0, s.size() - 1);
      int v = atoi(s.c_str());
      int cand = v - n;
      dbg(v, s, i);
      if (cand > 0 && cand % s.size() == i + 1) {
        ans.push_back(cand);
      }
    }
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
