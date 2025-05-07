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
  vector<int> rows(n + 1);
  vector<int> cols(n + 1);
  for (int i = 2; i <= n; i += 2) {
    rows[i] = 1;
    cols[i] = 1;
  }
  int cnt_r = n, cnt_c = n;
  while (q--) {
    string s;
    cin >> s;
    int x;
    cin >> x;
    if (s == "ROW") {
      cnt_r -= (x > 1 && rows[x] != rows[x - 1]) + (x < n && rows[x] != rows[x + 1]);
      rows[x] ^= 1;
      cnt_r += (x > 1 && rows[x] != rows[x - 1]) + (x < n && rows[x] != rows[x + 1]);
    } else {
      cnt_c -= (x > 1 && cols[x] != cols[x - 1]) + (x < n && cols[x] != cols[x + 1]);
      cols[x] ^= 1;
      cnt_c += (x > 1 && cols[x] != cols[x - 1]) + (x < n && cols[x] != cols[x + 1]);
    }
    cout << cnt_r * cnt_c << '\n';
  }
}

