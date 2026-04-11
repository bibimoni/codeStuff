/**
 * Author: distiled
 */
#include <algorithm>
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
  int n, q;
  cin >> n >> q;

  struct Q {
    string ss;
    int p, type;
    int idx;
    Q() {}
  };
  vector<Q> que;
  for (int i = 0; i < q; i++) {
    Q qq;
    cin >> qq.type >> qq.p;
    if (qq.type == 2) {
      cin >> qq.ss;
    }
    qq.idx = i;
    que.push_back(qq);
  }

  reverse(que.begin(), que.end());
  int cur = 0;
  vector<set<int>> tt(n + 1);
  int t = q - 1;
  for (auto qq : que) {
    if (cur == 0) {
      if (qq.type == 3) {
        cur = qq.p;
      }
    } else {
      if (qq.type == 1) {
        cur = 0;
      }
    }
    tt[cur].insert(t);
    t -= 1;
  }

  reverse(que.begin(), que.end());
  t = 0;
  string ans = "";
  for (auto qq : que) {
    if (qq.type == 2 && tt[qq.p].find(t) != tt[qq.p].end()) {
      ans += qq.ss;
    }
    t += 1;
  }

  cout << ans << '\n';
}
