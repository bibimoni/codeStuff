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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i].first;
    }
    for(int i = 1; i <= n; i++) {
      cin >> a[i].second;  
    }
    sort(a.begin() + 1, a.end(), [&] (pair<int, int> i, pair<int, int> j) {
      return abs(i.second) < abs(j.second);
    });
    int shots = 0;
    bool ok = true;
    int leftOver = 0;
    for(int i = 1; i <= n; i++) {
      while(i <= n && leftOver > 0) {
        dbg(a);
        if(leftOver >= a[i].first) {
          leftOver -= a[i].first;
          a[i].first = 0;
          i++;
        }
        else {
          a[i].first -= leftOver;
          leftOver = 0;
        }
      }
      if(i == n + 1)
        break;
      if(abs(a[i].second) - shots <= 0) {
        ok = false;
        break;
      }
      int cnt = ceil(a[i].first / (double) k);
      if(abs(a[i].second) - cnt - shots < 0) {
        ok = false;
        break;
      }     
      shots += cnt;
      leftOver += k * cnt - a[i].first;
      a[i].first = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


