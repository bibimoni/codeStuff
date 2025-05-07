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
  int n, m, k;
  cin >> n >> m >> k;
  if ((2 * m * n) % k != 0) {
    cout << "NO\n";
    return 0;
  }
  int S = (2 * n * m) / k;
  int a = sqrt(S);
  int b = S / a;
  cout << "YES\n0 0\n";
  
  if (n < m) {
    if (a > b) {
      swap(a, b);
    }
  } else {
    if (a < b) {
      swap(a, b);
    }
  }
  cout << "0 " << b << '\n';
  cout << a << " 0" << '\n';
}

