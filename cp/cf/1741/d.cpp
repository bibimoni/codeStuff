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
    int m;
    cin >> m;
    vector<int> p(m + 1);
    bool ok = true;
    for(int i = 1; i <= m; i++) {
      cin >> p[i];
    }
    if(m == 1) {
      cout << "0\n";
      continue;
    }
    for(int i = 1; i <= m; i += 2) {
      int p1 = p[i], p2 = p[i + 1];
      if(p1 < p2) swap(p1, p2);
      if(p1 % 2 != 0 || p2 % 2 == 0 || p2 + 1 != p1)
        ok = false;
    }
    if(!ok) {
      cout << "-1\n";
      continue;
    }
    function<int(int, int)> solve = [&] (int l, int r) -> int {
      int mid = (l + r) >> 1;
      int maxRight = 1, minLeft = m;
      if(r - l + 1 == 2) {
        if(p[l] > p[r]) {
          swap(p[l], p[r]);
          return 1;
        }
        else {
          return 0;
        }
      } 
      for(int i = l; i <= mid; i++) {
        minLeft = min(minLeft, p[i]);
      }
      for(int i = mid + 1; i <= r; i++) {
        maxRight = max(maxRight, p[i]);
      }
      int sl = solve(l, mid), sr = solve(mid + 1, r);
      if(minLeft > maxRight) {
        int half = (r - l + 1) / 2;
        for(int i = l; i <= mid; i++) {
          swap(p[i], p[i + half]);
        }
        return 1 + sl + sr;
      }
      else {
        return sl + sr;
      }
    };
    int ans = solve(1, m);
    ans = (is_sorted(p.begin(), p.end()) ? ans : -1);
    cout << ans << '\n';
  }
}


