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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n + 1], maxA = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    maxA = max(maxA, a[i]);
  }
  map<int, int> f1, f2, f;
  for(int i = 1; i <= n; i++) {
    f2[a[i] + 1] += 2;
  } 
  f1[0] = -n;
  for(int i = 1; i <= maxA; i++) {
    f1[i] = f1[i - 1] + f2[i];
  }
  for(int i = 1; i <= n; i++) {
    f[0] += a[i];
  }
  int ans = INF;
  for(int i = 1; i <= maxA; i++) {
    f[i] = f[i - 1] + f1[i];
    ans = min(ans, f[i]);
  }
  cout << ans;
}

