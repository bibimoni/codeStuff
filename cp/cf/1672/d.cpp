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
    vector<int> a(n + 1);
    vector<int> posa(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      posa[a[i]] = i;
    }
    vector<int> b(n + 1);
    vector<int> posb(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      posb[b[i]] = i;
    }
    sort(a.begin() + 1, a.end(), [&] (int i, int j) {
      return posa[i] < posa[j];
    });
    sort(b.begin() + 1, b.end(), [&] (int i, int j) {
      return posb[i] < posb[j];
    });
    cout << (a == b ? "YES\n" : "NO\n");
  }
}

