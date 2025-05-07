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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 1; i <= n - 1; i++) {
      cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    sort(b.begin() + 1, b.end());
    auto bs = [&] (int val) -> int {
      int l = 1, r = n, ret = n + 1;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(val < b[mid]) {
          ret = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      return ret;
    };
    auto f = [&] (int val) -> int {
      int curr = 0;
      auto t = a;
      t.push_back(val);
      sort(t.begin() + 1, t.end());
      for(int i = 1; i <= n; i++) {
        curr = max(curr, bs(t[i]) - i);
      }  
      return curr;
    };
    int l = 1, r = m, ret = 0, cmp = f(1);
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(f(mid) == cmp) {
        l = mid + 1;
        ret = mid;
      }
      else {
        r = mid - 1;
      }
    }
    cout << (ret) * cmp + f(ret + 1) * (m - (ret + 1) + 1) << '\n';

  }
}

