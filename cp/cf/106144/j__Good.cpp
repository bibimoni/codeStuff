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
    string s;
    cin >> s;
    string t = s;
    vector<int> ans;
    for (int i = 0; i < 1000000; i++) {
      t = t.back() + t.substr(0, t.size() - 1); 
      int v = atoi(t.c_str());
      if (v == atoi(s.c_str()) + (i + 1))
        ans.push_back((i + 1));
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
}
