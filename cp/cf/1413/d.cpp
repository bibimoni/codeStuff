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
  int n;
  cin >> n;
  set<int> cur;
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), 0);
  set<int, greater<int>> rem(p.begin() + 1, p.end());
  map<int, int> ord;
  bool ok = true;
  int id = 0;
  vector<pair<char, int>> que;
  for (int i = 0; i < n * 2; i++) {
    char x;
    cin >> x;
    if (x == '+') {
      que.push_back({'+', -1});
      int lst = *rem.begin();
      rem.erase(rem.begin());
      ord[lst] = id;
      cur.insert(lst);
      id += 1;
    } else {
      int v;
      cin >> v;
      que.push_back({'-', v});
      if (cur.size() && (*cur.begin() == v)) {
        cur.erase(v);
        rem.erase(v);
      } else {
        if (!cur.size() || (*cur.begin() < v)) {
          ok = false;
        } else {
          int mn = *cur.begin();
          ord[v] = id;
          id += 1;
          rem.erase(v);
          ord.erase(mn);
          rem.insert(mn);
          cur.erase(mn);
        }
      }
    }
    // dbg(ord);
  }
  if (!ok || int(ord.size()) != n) {
    cout << "NO\n";
  } else {
    vector<pair<int, int>> ans;
    for (auto &[k, v] : ord) {
      ans.push_back({v, k});
    }
    sort(ans.begin(), ans.end());
    cur.clear();
    id = 0;
    for (auto &[k, v] : que) {
      if (k == '+') {
        if (id >= int(ans.size())) {
          ok = false;
          break;
        }
        cur.insert(ans[id].second);
        id += 1;
      } else {
        ok &= cur.size() && *cur.begin() == v;
        if (!ok) {
          break;
        }
        cur.erase(v);
      }
    }
    if (!ok) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto &[_, v] : ans) {
        cout << v << ' ';
      }
    }
  }
}
