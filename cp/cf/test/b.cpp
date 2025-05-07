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
    int n, k;
    cin >> n >> k;
    if ((n + 1) / 2 == k) {
      cout << "1\n1\n";
      continue;
    }
    if (k == 1 || k == n) {
      cout << "-1\n";
      continue;
    }
    // 1 2 3 4 5 6 7 8 [9] 10 11 12 13
    int left = k - 1, right = n - k;
    // case 1 1
    if (left % 2 != 0 && right % 2 != 0) {
      cout << "3\n1 " << k << ' ' << k + 1 << '\n';
      continue;
    } 
    // case 2 2
    if (left % 2 == 0 && right % 2 == 0) {
      cout << "5\n1 2 " << k << ' ' << k + 1 << ' ' << k + 2 << '\n';
      continue;
    } 
    cout << "-1\n";
  }
}


  