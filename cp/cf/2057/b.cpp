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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x] += 1;
    }
    int mx = 0, e = -1;
    vector<int> s;
    for (auto [u, v] : cnt) {
      s.push_back(v);
    }
    sort(s.begin(), s.end());
    int ans = s.size();
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] <= k) {
        ans -= 1;
        k -= s[i];
      }
    }
    cout << ans << "\n";
  }
}


