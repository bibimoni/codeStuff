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
    int n, k; cin >> n >> k;
    int a[n + 1]; 
    map<int, int> idx;
    bool ok = false;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if(not (k & 1)) {
      cout << "0"; 
      continue;
    } 
    for(int i = 1; i <= n; i++) {
      if(k > a[i] && idx[k - a[i]] != 0 && ((a[i] & 1) ^ (a[idx[k - a[i]]] & 1))) {
        ok = true;
        break;
      }
      idx[a[i]] = i;
    }
    cout << (int)ok;
  }
}

