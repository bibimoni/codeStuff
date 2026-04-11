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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }

    if (cnt[1] + 2 * cnt[2] > s) {
      for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
      }
    } else if (cnt[1] + 2 * cnt[2] == s) {
      cout << "-1\n";
    } else if (s - cnt[1] - 2 * cnt[2] == 1) {
      for (int i = 0; i < cnt[0]; i++) {
        cout << "0 ";
      }
      for (int i = 0; i < cnt[2]; i++) {
        cout << "2 ";
      }
      for (int i = 0; i < cnt[1]; i++) {
        cout << "1 ";
      }
      cout << '\n';
    } else {
      cout << "-1\n";
    }
  }
}
