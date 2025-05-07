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
    string s;
    cin >> s;
    int sum = 0;
    int c_2 = 0, c_3 = 0;
    for (char c : s) {
      sum += c - '0';
      c_2 += c == '2';
      c_3 += c == '3';
    }
    sum %= 9;
    bool ans = false;
    for (int c2 = 0; c2 <= min(c_2, (int)10); c2++) {
      for (int c3 = 0; c3 <= min(c_3, (int)3); c3++) {
        ans |= (sum + c2 * 2 + c3 * 6) % 9 == 0;
      }
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
}


