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
  string s, t;
  cin >> s >> t;
  int n = s.size();
  vector<string> ans;
  vector<pair<char, int>> pos;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      continue;
    }
    pos.push_back({t[i], i});
  }
  string curr = s;
  vector<int> mark(pos.size(), 0);
  for (int i = 0; i < pos.size(); i++) {
    int pick = -1;
    string tmp = curr;
    for (int j = 0; j < pos.size(); j++) {
      if (mark[j]) {
        continue;
      }
      auto [c, id] = pos[j];
      string nxt = curr;
      nxt[id] = c;
      if (pick == -1 || nxt < tmp) {
        tmp = nxt;
        pick = j;
      }
    }
    mark[pick] = 1;
    ans.push_back(tmp);
    curr = tmp;
  }
  cout << ans.size() << '\n';
  for (string &b : ans) {
    cout << b << '\n';
  }
}


