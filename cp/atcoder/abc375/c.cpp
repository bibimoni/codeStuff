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
  vector<string> a(n + 1);
  // (x, y) -> (y, n + 1 - x) -> (n + 1 - x, n + 1 - y) 
  // -> (n + 1 - y, n + 1 - (n + 1 - x)) = (n + 1 - y, x) -> (x, y)
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  vector<string> tmp(n + 1, string(n + 1, '.'));
  auto go = [&] (int x, int y) -> void {
    // dbg(x, y);
    tmp[y][n + 1 - x] = a[x][y];
  };
  auto make = [&] (int x, int y) -> void {
    // dbg(x, y);
    a[x][y] = tmp[x][y];
  };
  for (int i = 1; i * 2 <= n; i++) {
    int op = i % 4;
    while (op--) {
      int t_1 = i, t_2 = n - i + 1;
      for (int k = i; k <= n - i + 1; k++) {
        go(t_1, k);
      }        
      for (int k = i + 1; k <= n - i; k++) {
        go(k, t_1);
        go(k, t_2); 
      }
      for (int k = i; k <= n - i + 1; k++) {
        go(t_2, k);
      }

      for (int k = i; k <= n - i + 1; k++) {
        make(t_1, k);
      }        
      for (int k = i + 1; k <= n - i; k++) {
        make(k, t_1);
        make(k, t_2);
      }
      for (int k = i; k <= n - i + 1; k++) {
        make(t_2, k);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i].substr(1) << '\n';
  }
}


