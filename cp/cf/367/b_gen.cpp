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
  int n, m, p;
  cin >> n >> m >> p;
  cout << n << ' ' << m << ' ' << p << '\n';
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cout << x + int(1e7) << " \n"[i == n - 1];
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    cout << x + int(1e7) << " \n"[i == m - 1]; 
  }
}

