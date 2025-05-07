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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string s; cin >> s;
  vector<char> ans;
  for(int i = s.size() - 1; i >= 0; i--) {
    if(s[i] == '.') break;
    ans.push_back(s[i]);
  }
  reverse(ans.begin(), ans.end());
  for(char i : ans) {
    cout << i;
  }
}


