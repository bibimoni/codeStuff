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
  int n, t;
  cin >> n >> t;
  vector<int> rows(n + 1, 0);
  vector<int> cols(n + 1, 0);
  int top_left = 0, top_right = 0;
  int ans = -1;
  for (int i = 0; i < t; i++) {
    int v;
    cin >> v;
    int r = v / n + (v % n != 0);
    int c = (v % n == 0 ? n : v % n);
    rows[r] += 1;
    cols[c] += 1;
    if (r == c) {
      top_left += 1;
    }
    if (n - r + 1 == c) {
      top_right += 1;
    }
    if (ans != -1) {
      continue;
    }
    if (rows[r] == n || cols[c] == n || top_left == n || top_right == n) {
      ans = i + 1;
    }
  }
  cout << ans << '\n';
}


