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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<int>());
    int ans = 0;
    for(int j = 1, i = 1; i <= n; i += 2) {
      ans += a[j++];
    }
    for(int j = n, i = 2; i <= n; i += 2) {
      ans -= a[j--];
    }
    cout << ans << '\n';
  }
}


