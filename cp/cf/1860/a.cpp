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
    int n = s.size();
    map<char, int> cnt;
    for (char c : s) {
      cnt[c] += 1;
    }
    string ans_1 = string(n, '(') + string(n, ')');
    string ans_2 = "";
    for (int i = 0; i < n; i++) {
      ans_2 += "()";
    }    
    if (ans_1.find(s) == string::npos) {
      cout << "YES\n" << ans_1 << "\n";
    }
    else if (ans_2.find(s) == string::npos) {
      cout << "YES\n" << ans_2 << "\n";
    } else {
      cout << "NO\n";
    }

  }
}

