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
  string s;
  cin.ignore();
  getline(cin, s); 
  vector<int> a;
  for (int i = 0, j = 0; i < s.size(); i++) {
    if (i == s.size() - 1 || s[i] == ' ' || s[i] == '-') {
      a.push_back(i - j + 1);
      j = i + 1;
    }
  }
  int l = 1, r = s.size(), ans = s.size();
  while (l <= r) {
    int m = (l + r) >> 1;
    int cnt = k, curr = 0;
    for (auto w : a) {
      if (w > m) {
        cnt = -1;
        break;
      }
      if (curr + w > m) {
        cnt -= 1;
        curr = w;
      } else {
        curr += w;
      }
    }
    if (curr > 0) {
      cnt -= 1;
    }
    if (cnt >= 0) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  cout << ans << '\n';
}

