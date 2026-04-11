/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    int winner = 0;
    for (int bit = 21; bit >= 0; bit--) {
      int first = -1;
      array<int, 2> cnt1{0, 0};
      for (int i = n - 1; i >= 0; i--) {
        cnt1[0] += (a[i] >> bit) & 1;
        cnt1[1] += (b[i] >> bit) & 1;
        if (((a[i] >> bit) & 1) != ((b[i] >> bit) & 1)) {
          if (first == -1) {
            first = i;
          }
        }
      }
      if (cnt1[0] % 2 != cnt1[1] % 2 && first != -1) {
        if (first % 2 == 0) {
          winner = 1;
        } else {
          winner = 2;
        }
        break;
      }
    }

    if (winner == 0) {
      cout << "Tie\n";
    } else if (winner == 1) {
      cout << "Ajisai\n";
    } else {
      cout << "Mai\n";
    }
  }
}
