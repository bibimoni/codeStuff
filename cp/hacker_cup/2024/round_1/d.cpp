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
  const int N = int(1e7 + 5);
  for (int ttt = 1; ttt <= tt; ttt++) {
    string s;
    cin >> s;
    int k;
    cin >> k; 
    string t = s;
    int n = s.size();
    vector<vector<char>> sa(n);
    for (int i = 0; i < n; i++) {
      int mx = 0;
      if (s[i] != '?') {
        continue;
      }
      for (char c = '0'; c <= '9'; c++) {
        t[i] = c;
        int cnt = 0;
        if (i > 0 && stoi(string(1, t[i - 1]) + string(1, t[i])) <= 26) {
          cnt += 1;
        }
        // if (i < n - 1 && stoi(string(1, t[i]) + string(1, t[i + 1])) <= 26) {
        //   cnt += 1;
        // }
        mx = max(mx, cnt);
      }
      for (char c = '0'; c <= '9'; c++) {
        t[i] = c;
        int cnt = 0;
        if (i > 0 && stoi(string(1, t[i - 1]) + string(1, t[i])) <= 26) {
          cnt += 1;
        }
        // if (i < n - 1 && stoi(string(1, t[i]) + string(1, t[i + 1])) <= 26) {
        //   cnt += 1;
        // }
        if (cnt == mx) {
          sa[i].push_back(c);
        }
      }
    }
    dbg(sa);
    cout << "Case #" << ttt << ": ";

  }
}


