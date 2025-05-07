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
  string s;
  cin >> s;
  vector<int> ans;
  int cur = 0;
  for (char i : s) {
    if (i == '|') {
      ans.push_back(cur);
      cur = 0;
    } else {
      cur += 1;
    }
  }
  ans.erase(ans.begin());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }
}


