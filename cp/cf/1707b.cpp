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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    bool has0 = false;
    while (a.size() > 1) {
      vector<int> b;
      for (int i = 0; i < a.size() - 1; i++) {
        b.push_back(a[i + 1] - a[i]);
      }
      dbg(b);
      sort(b.begin(), b.end());
      ans = b[0];
      if (b[b.size() - 1] == 0) {
        break;
      }
      swap(a, b);
    }
    cout << ans << '\n';
  }
}

