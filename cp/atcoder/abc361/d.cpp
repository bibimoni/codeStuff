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

const int INF = int(1e9);

map<string, int> ans;

void Try(string curr, string &t, int times) {
  if (curr == t) {
    if (!ans.count(t)) {
      ans[t] = times;
      return;
    } else {
      ans[t] = min(ans[t], times);
      return;
    }
  }
  if (times >= curr.size() / 2 + 2) {
    return;
  }
  if (ans.count(curr) && ans[curr] <= times) {
    return;
  } else {
    ans[curr] = times;
  }
  int idx = 0;
  for (int i = 0; i < curr.size() - 1; i++) {
    if (curr[i] == '.') {
      idx = i;
      break;
    }
  }
  for (int i = 0; i < curr.size() - 1; i++) {
    if (i == idx + 1 || i + 1 == idx || i == idx + 1 || i + 1 == idx) {
      continue;
    }
    string s = curr;
    s[idx] = curr[i];
    s[idx + 1] = curr[i + 1];
    s[i] = '.';
    s[i + 1] = '.';
    Try(s, t, times + 1);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  t += "..";
  s += "..";
  Try(s, t, 0);
  if (!ans.count(t) || ans[t] == INF) {
    cout << "-1\n";
  } else {
    cout << ans[t];
  }
}


