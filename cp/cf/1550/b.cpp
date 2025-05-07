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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<int> len;
    int cur = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        len.push_back(cur);
        cur = 1;
      } else {
        cur += 1;
      }
    }
    len.push_back(cur);
    // dbg(len);
    if (len.size() == 1) {
      cout << max((a + b) * n, a * n + b) << '\n';
      continue;
    }
    int sz = len.size();
    cout << max(n * (a + b), a * n +(sz / 2 + 1) * b) << '\n'; 

  }
}

