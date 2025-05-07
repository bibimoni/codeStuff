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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c;
    int prev = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] - '0' == 0 && s[i] - '0' == prev) {
        continue;
      }
      c.push_back(s[i] - '0');
      prev = s[i] - '0';
    }
    cout << (accumulate(c.begin(), c.end(), 0ll) > c.size() / 2 ? "Yes\n" : "No\n");
  }
}


