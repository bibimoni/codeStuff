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
  string s;
  cin >> s;
  vector<int> bs, as;
  for (int i = 0; i < n * 2; i++) {
    if (s[i] == 'B') {
      bs.push_back(i);
    } else {
      as.push_back(i);
    }
  }
  auto find_ans = [&](string &t) -> int {
    vector<int> bt, at;
    for (int i = 0; i < n * 2; i++) {
      if (t[i] == 'B') {
        bt.push_back(i);
      } else {
        at.push_back(i);
      }
    }
    int ret1 = 0, ret2 = 0;
    for (int i = 0; i < n; i++) {
      ret1 += abs(as[i] - at[i]);
      ret2 += abs(bs[i] - bt[i]);
    }
    return min(ret1, ret2);
  };
  string t1 = "", t2 = "";
  for (int i = 0; i < n * 2; i++) {
    if (i % 2 == 0) {
      t1 += 'A';
      t2 += 'B';
    } else {
      t1 += 'B';
      t2 += 'A';
    }
  }

  cout << min(find_ans(t1), find_ans(t2)) << '\n';
}
