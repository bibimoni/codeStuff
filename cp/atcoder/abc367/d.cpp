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
  int n, m;
  cin >> n >> m;  
  vector<int> a(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  int cur = 0;
  mp[0] += 1;
  for (int i = 0; i < n - 1; i++) {
    cur += a[i];
    mp[cur % m] += 1;
  }
  int t = n, i = n - 1, j = 0, trail = 0;
  int ans = 0;
  while (t--) {
    ans += mp[(cur + a[i]) % m];
    dbg(i, mp[(cur + a[i]) % m]);
    cur += a[i];
    trail += a[j];
    mp[trail] -= 1;
    mp[cur % m] += 1;
    j += 1;
    i = (i + 1) % n;
  }
  cout << ans << '\n';
}


