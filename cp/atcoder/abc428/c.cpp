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
  int q;
  cin >> q;
  int len = 0;
  vector<int> bad;
  set<int, greater<int>> open;
  map<int, int> mp;
  vector<char> e;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      len += 1;
      char c;
      cin >> c;
      if (c == ')') {
        e.push_back(')');
        if (open.size() == 0) {
          bad.push_back(len);
          cout << "No\n";
        } else {
          auto id = *open.begin();
          open.erase(id);
          mp[len] = id;
          cout << (!open.size() && !bad.size() ? "Yes\n" : "No\n");
        }
      } else {
        e.push_back('(');
        open.insert(len);
        cout << "No\n";
      }
    } else {
      char prev = e.back();
      e.pop_back();
      if (prev == ')') {
        if (bad.size() && bad.back() == len) {
          bad.pop_back();
        } else {
          int id = mp[len];
          open.insert(id);
          mp.erase(len);
        }
      } else {
        open.erase(open.begin());
      }

      cout << (!open.size() && !bad.size() ? "Yes\n" : "No\n");
      len -= 1;
    }
  }
}
