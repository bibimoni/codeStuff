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
    string s, r;
    cin >> n >> s >> r;    
    int idx = -1;
    s = " " + s;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] + s[i] - '0';
    }
    int sum = 0;
    for (int i = 0; i < n - 2; i++) {
      sum += (r[i] - '0') ^ 1;
    }
    bool ok = false;
    for (int i = 1; i + 1 <= n; i++) {
      if (s[i] != s[i + 1]) {
        ok |= p[i - 1] + p[n] - p[i + 1] == sum;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


