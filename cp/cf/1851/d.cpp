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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n - 1; i++) {
      cin >> a[i];
    }

    vector<int> diff;
    int pr = 0;
    for (int i = 1; i <= n - 1; i++) {
      diff.push_back(a[i] - pr);
      pr = a[i];
    }
    sort(diff.begin(), diff.end());
    vector<int> pos(n + 1);
    for (int i = 0; i < n - 1; i++) {
      if (diff[i] <= n) {
        pos[diff[i]] += 1;
      }
    }
    vector<int> miss;

    for (int i = 1; i <= n; i++) {
      if (pos[i] == 0) {
        miss.push_back(i);
      }
    }

    if (miss.size() == 1 && a[n - 1] != (n * (n + 1) / 2) && n * (n + 1) / 2 - a[n - 1] == miss[0]) {
      cout << "YES\n";
      continue;
    }
    if (miss.size() == 1 && (miss[0] == n || miss[0] == 1)) {
      cout << "YES\n";
      continue;
    }
    if (miss.size() != 2) {
      cout << "NO\n";
      continue;
    }

    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      if ((diff[i] <= n && pos[diff[i]] > 1) || diff[i] > n) {
        if (miss.size() == 2 && (miss[0] + miss[1] == diff[i])) {
          ok = true;
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");

  }
}

