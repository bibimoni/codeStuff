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
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  // (a1 + ai) % mod + (a2 + ai) % mod + (a3 + ai) % mod
  const int MOD = (int) 1e8;
  int ans = 0, curr = a[0];
  vector<int> s;
  s.push_back(a[0]);
  auto bs = [&] (int x) -> int {
    int ret = -1, l = 0, r = s.size() - 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(s[mid] + x >= MOD) {
        r = mid - 1;
        ret = mid;
      }
      else {
        l = mid + 1;
      }
    }
    return (ret == -1 ? 0 : s.size() - 1 - ret + 1);
  };
  for(int i = 1; i < n; i++) {
    curr += a[i] - bs(a[i - 1]) * MOD;
    ans += curr;
    dbg(ans, bs(a[i]))
    s.push_back(a[i]);
  }
  cout << ans << '\n';
}


