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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto ask = [&] (int a, int b, int c) -> int {
      cout << "? " << a << ' ' << b << ' ' << c << '\n';
      cout.flush();
      int ans;
      cin >> ans;
      return ans;
    };
    int prev = ask(1, 2, 3);
    vector<int> p;
    for (int i = 4; i <= n; i++) {
      int curr = ask(i - 2, i - 1, i);
      if (prev != curr) {
        p.push_back(i - 2);
        p.push_back(i - 1);
        break;
      } 
      prev = curr;
    }
    vector<int> ans;
    int notI = 1;
    for (int i = 1; i <= n; i++) {
      if (i != p[0] && i != p[1]) {
        if (ask(p[0], p[1], i) == 0) {
          ans.push_back(i);
        } else {
          notI = i;
        }
      }
    }
    if (ask(ans.back(), notI, p[0]) == 0) {
      ans.push_back(p[0]);
    } else {
      ans.push_back(p[1]);
    }
    cout << "! " << ans.size() << ' ';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    cout.flush();
  }
}

