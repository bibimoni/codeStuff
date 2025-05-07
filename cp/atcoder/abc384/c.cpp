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
  vector<int> p(5);
  cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4];
  vector<pair<int, string>> ans;
  for (int i = 0; i < (1 << 5); i++) {
    int cur = 0;
    string s;
    for (int j = 0; j < 5; j++) {
      if ((i >> j) & 1) {
        cur += p[j];
        s += string(1, char(j + 'A'));
      }
    }
    ans.push_back({cur, s});
  }
  sort(ans.begin(), ans.end(), [&] (pair<int, string> &i, pair<int, string> &j) {
    if (i.first != j.first) {
      return i.first > j.first;
    } else {
      return i.second < j.second;
    }
  });
  for (auto [_, s] : ans) {
    cout << s << '\n';
  }
}


