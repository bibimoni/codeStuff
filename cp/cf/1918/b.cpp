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
    vector<int> pos(n + 1, 0);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pos[a[i]] = x;
    }
    sort(a.begin(), a.end());
    int curr = 1;
    for(int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
    for(int i = 0; i < n; i++) {
      cout << pos[a[i]] << " \n"[i == n - 1];
    }
  }
}


