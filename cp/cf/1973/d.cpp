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
    cout.flush();
    auto ask = [&] (int l, int x) -> int {
      int res;
      cout << "? " << l << ' ' << x << '\n';
      cout.flush();
      cin >> res;
      cout.flush();
      return res;
    };
    auto answer = [&] (int ans) -> int {
      cout << "! " << ans << '\n';
      cout.flush(); 
      int res;
      cin >> res;
      cout.flush();
      return res;
    };
    int mx = 1;
    for(int i = 1; i <= n; i++) {
      if(ask(1, i * n) == n) {
        mx = i;
        break;
      }
    }
    dbg(mx)
    int ans = -1;
    for(int i = (n / k); i >= 1; i--) {
      int m = mx * i, l = 1;
      bool ok = false;
      for(int i = 1; i <= k; i++) {
        if(l > n)
          break;
        l = ask(l, m);
        if(l == n + 1)
          break;
        if(l == n && i == k) {
          ok = true;
        }
        l++;
      } 
      if(ok) {
        ans = m;
        break;
      }
    }
    if(answer(ans) == -1) 
      break;
  }
}


