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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  while (true) {
    if (a[0] <= 0 || a[1] <= 0) {
      break;
    }
    sort(a.begin(), a.end(), greater<int>());
    a[1] -= 1;
    a[0] -= 1;
    ans += 1;
    sort(a.begin(), a.end(), greater<int>());
  }
  cout << ans << '\n';
}


