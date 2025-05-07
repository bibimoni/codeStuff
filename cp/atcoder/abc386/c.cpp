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
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;
  if (abs((int)(s.size() - t.size())) == 1) {
    if (s.size() < t.size()) {
      swap(s, t);
    }
    int l = 0;
    for (; l < t.size(); l++) {
      if (s[l] != t[l]) {
        break;
      }
    }
    int r = s.size();
    for (; r - 1 >= 0; r--) {
      if (s[r] != t[r - 1]) {
        break;
      }
    }
    cout << (r <= l ? "Yes\n" : "No\n");
  } else if (s.size() == t.size()) {
    int diff = 0;
    for (int i = 0; i < s.size(); i++) {
      diff += s[i] != t[i];
    }
    cout << (diff <= 1 ? "Yes\n" : "No\n");
  } else {
    cout << "No\n";
  }
}


