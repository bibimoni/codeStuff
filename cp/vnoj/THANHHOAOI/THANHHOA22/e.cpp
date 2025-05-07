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
  freopen("MARIO.INP", "r", stdin);
  freopen("MARIO.OUT", "w", stdout);
  int n, x, k;
  cin >> n >> x >> k;
  vector<pair<int, int>> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  vector<int> pref(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i].second;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(a[i].first + k >= x) {
      int dist = ((a[i].first + k - x) / 2 + x - a[i].first);
      // dbg(dist);
      int l = 1, r = n, pos = i;
      while(l <= r) {
        int mid = (l + r) / 2;
        // dbg(mid, l, r);
        if(a[mid].first > a[i].first + dist) {
          r = mid - 1;
        }
        else {
          l = mid + 1;
          pos = mid;
        }
      }
      ans = max(ans, pref[pos] - pref[i - 1]);
      // dbg(i, pos);
    }
  }
  cout << ans;
}


