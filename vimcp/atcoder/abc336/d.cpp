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
const int INF = (int) 2e9;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(n == 1) {
    cout << "1\n";
    return 0;
  }
  int l[n], r[n];
  memset(l, INF, sizeof l);
  memset(r, INF, sizeof r);
  l[0] = 1, r[n - 1] = 1;
  for(int i = 1; i < n; i++) {
    l[i] = min(a[i], l[i - 1] + 1);
    
  }
  for(int i = n - 2; i >= 0; i--) {
    r[i] = min(a[i], r[i + 1] + 1);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, min(r[i], l[i]));
  }
  cout << ans; 
}


