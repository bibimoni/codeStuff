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

const int INF = (int) 1e18, N = (int) 1e5 + 5;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n + 2]; vector<int> pref(n + 2, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pref[i] = pref[i - 1] + a[i];
    }
    pref[n + 1] = pref[n];
    a[n + 1] = 0;
    int l = 0, r = 1e18, ans = 1e18;
    auto possible = [&] (int bound) {
      vector<int> dp(n + 2);
      deque<int> dq;
      dq.push_back(0);
      dp[0] = 0;
      for(int i = 1; i <= n + 1; i++) {
        while(dq.size() && pref[i - 1] - pref[dq.front()] > bound) {
          dq.pop_front();
        }
        dp[i] = dp[dq.front()] + a[i];
        while(dq.size() && dp[i] <= dp[dq.back()]) {
          dq.pop_back();
        }
        dq.push_back(i);
      }
      return dp[n + 1] <= bound;
    };
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(possible(mid)) {
        r = mid - 1;
        ans = mid;
      }
      else {
        l = mid + 1;
      }
    }
    cout << ans << '\n';
  }
}


