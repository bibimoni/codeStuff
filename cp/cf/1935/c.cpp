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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> a(n + 1);
    int sz[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), [&] (pair<int, int> i, pair<int, int> j) {
      return i.second < j.second;
    });
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      multiset<int, greater<int>> s;
      int curr = 0;
      for(int j = i; j <= n; j++) {
        s.insert(a[j].first);
        curr += a[j].first;
        int bound = l - (a[j].second - a[i].second);
        if(bound < 0)
          break;
        while(bound < curr) {
          curr -= *s.begin();
          s.erase(s.begin());
        }
        ans = max(ans, (int)s.size());
      }
    }
    cout << ans << '\n';
  }
}


