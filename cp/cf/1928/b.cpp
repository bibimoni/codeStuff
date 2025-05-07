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
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int ans = 0;
    int j = 0;
    for(int i = 0; i < a.size(); i++) {
      while(j <= i && a[i] - a[j] + 1 > n) {
        j++;
      }
      if(a[i] - a[j] + 1 <= n) {
        ans = max(ans, i - j + 1);
      }
    }
    cout << ans << '\n';
  }
}


