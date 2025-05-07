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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = is_sorted(a.begin(), a.end());
    for(int i = 0; i < n - 1; i++) {
      vector<int> b;
      for(int j = i + 1; j < n; j++) {
        b.push_back(a[j]);
      }
      for(int j = 0; j <= i; j++) {
        b.push_back(a[j]);
      }
      ok |= is_sorted(b.begin(), b.end());
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}



