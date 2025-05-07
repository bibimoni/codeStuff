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
    int diff = -1;
    for(int i = 0; i < n - 1; i++) {
      if(a[i] - a[0] != a[n - 1] - a[i + 1]) {
        diff = i;
      }
    }
    if(diff == -1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout << string(diff + 1, 'R') << string(n - diff - 1, 'B') << '\n';
  }
}


