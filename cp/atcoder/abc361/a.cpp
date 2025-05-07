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
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (i == k)
      cout << x << ' ';
    cout << t << ' ';
  }
  if (k == n) {
    cout << x << ' ';
  }
}


