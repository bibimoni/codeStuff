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
    int n; cin >> n;
    map<string, bool> f;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i]] = true;
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
      bool ok = false;
      if(a[i].size() == 1) {
        ans[i] = 0; continue;
      }
      for(int j = 0; j < a[i].size() - 1; j++) {
        if(f[a[i].substr(0, j + 1)] && f[a[i].substr(j + 1, a[i].size() - j)]) {
          ok = true;
          break;
        }
      }
      ans[i] = (int) ok;
    }
    for(int i : ans) cout << i;
    cout << '\n';
  }
}

