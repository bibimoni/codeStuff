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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (r - l > 47) {
      cout << "YES\n";
      continue;
    }
    vector<int> b(a.begin() + l, a.begin() + r + 1);
    sort(b.begin(), b.end());
    bool ok = false;
    int cnt = 0;
    for (int i = 2; i < b.size(); i++) {
      if (b[i - 1] + b[i - 2] > b[i]) {
        i += 2;
        cnt += 1;
      }
    }
    if (cnt >= 2) {
      cout << "YES\n";
      continue;
    }
    for (int i = 0; i + 5 < b.size(); i++) {
      for (int ic : {i + 3, i + 4, i + 5}) {
        for (int ia = i; ia < ic; ia++) {
          for (int ib = ia + 1; ib < ic; ib++) {
            if (b[ia] + b[ib] <= b[ic]) {
              continue;
            }
            vector<int> rem;
            for (int r = i; r <= i + 5; r++) {
              if (r != ia && r != ib && r != ic) {
                rem.push_back(r);
              }
            }
            if (b[rem[0]] + b[rem[1]] > b[rem[2]]) {
              ok = true;
            }
          }
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}

