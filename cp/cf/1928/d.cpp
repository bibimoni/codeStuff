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
    int n, b, x;
    cin >> n >> b >> x;
    int c[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> c[i];
      sum += c[i];
    }
    auto f = [&] (int k) {
      int ret = 0;
      for(int x : c) {
        int curr = x * (x - 1) / 2; // all possilbe pairs
        int y = x / k;
        curr -= (x % k) * y * (y + 1) / 2; // all pairs in same groups with size x / k + 1
        curr -= (k - x % k) * y * (y - 1) / 2; // all pairs in same groups with size x / k
        // dbg(curr, k, x);
        ret += curr;
      }
      // dbg(ret  b, k);
      return ret * b - (k - 1) * x;
    };
    int l = 1, r = sum;
    while(l + 1 < r) {
      int mid = (l + r) >> 1;
      if(f(mid) < f(mid + 1)) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    int ans = f(r);
    // dbg(r, f(3), ans);
    cout << (ans < 0 ? 0 : ans) << '\n';
  }
}


