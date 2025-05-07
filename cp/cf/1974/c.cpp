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
    map<pair<int, int>, int> cnt1, cnt2, cnt3;
    auto trip = [&] (int i) -> array<int, 3> {
      return {{a[i - 2], a[i - 1], a[i]}};
    };
    int ans = 0;
    map<array<int, 3>, int> cnt;
    for(int i = 3; i <= n; i++) {
      auto t = trip(i);
      ans += cnt3[{t[0], t[1]}] + cnt1[{t[1], t[2]}] + cnt2[{t[0], t[2]}] - cnt[t];
      cnt3[{t[0], t[1]}]++;
      cnt1[{t[1], t[2]}]++;
      cnt2[{t[0], t[2]}]++;
      cnt[t] += 3;
    }
    cout << ans << '\n';
  }
}


