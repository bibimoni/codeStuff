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
  int n;
  cin >> n;
  vector<string> s(n);
  bool ok = true;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (i > 0 && i < n - 1 && s[i] == s[i - 1] && s[i] == "sweet") {
      ok = false;
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
}


