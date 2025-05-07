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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k; cin >> n >> k;
    bool check = false;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
      if(a[i] > k) {
        cout << "YES\n1\n";
        check = true;
        break;
      }
    }
    if(check) continue;
    for(int i = 0; i < n; i++) {
      if(check) break;
      for(int j = i + 1; j < n; j++) {
        if(a[i] + a[j] > k) {
          cout << "YES\n2\n";
          check = true;
          break;
        }
      }
    }
    if(check) continue;
    cout << "NO\n";
  }
}

