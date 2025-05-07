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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  int cur = 0;
  for (int i = 3; i <= n; i++) {
    cur += s[i] == 'C' && s[i - 1] == 'B' && s[i - 2] == 'A';
  }
  while (q--) {
    int x;
    char c;
    cin >> x >> c;
    int cnt = 0;
    for (int k = max(int(1), x - 2); k <= min(n - 2, x); k++) {
      cnt += s[k + 2] == 'C' && s[k + 1] == 'B' && s[k] == 'A';
    }
    cur -= cnt;
    s[x] = c;
    cnt = 0;
    for (int k = max(int(1), x - 2); k <= min(n - 2, x); k++) {
      cnt += s[k + 2] == 'C' && s[k + 1] == 'B' && s[k] == 'A';
    }
    cur += cnt;
    cout << cur << '\n';
  }
}


