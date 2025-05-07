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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    vector<int> mark(n, 0);
    long double hp = log(x);
    for(int i = 0; i < n; i++) {
      vector<pair<int, int>> t;
      for(int j = 0; j < n; j++) {
        if(!mark[j])
          t.push_back({a[j], j});
      }
      sort(t.begin(), t.end(), greater<pair<int, int>>());
      for(int j = 0; j < t.size(); j++) {
        if(t[j].first <= x) {
          // hp += log(i + 2);
          x *= (i + 2);
          ans++;
          mark[t[j].second] = 1;
          break;
        }
      }
      for(int j = 0; j < n; j++) {
        if(!mark[j]) {
          a[j] *= (i + 1);
          // t[j] += log(i + 1);
        }
      }
      dbg(mark);
    }
    cout << ans << '\n';
  }
}


