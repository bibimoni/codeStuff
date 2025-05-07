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
    int a[n];
    map<int, int> f;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i]]++;
    }
    auto it = f.begin();
    if(it->second == 1) {
      cout << "YES\n";
      continue;
    } 
    sort(a, a + n);
    bool ok = false;
    for(int i = 0; i < n; i++) {
      if(a[i] % a[0] != 0) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


