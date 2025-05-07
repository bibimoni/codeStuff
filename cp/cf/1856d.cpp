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
    int n;
    cin >> n;
    cout.flush();
    auto ask = [&] (int l, int r) -> int {
      if(l == r)
        return 0;
      cout << "? " << l << ' ' << r << '\n';
      cout.flush();
      int ret;
      cin >> ret;
      cout.flush();
      return ret;
    };
    function<int(int, int)> Try = [&] (int l, int r) -> int {
      if(l == r)
        return l;
      int mid = (l + r) >> 1;
      int s = Try(l, mid), e = Try(mid + 1, r);
      if(ask(s, e) == ask(s, e - 1))
        return e;
      else 
        return s;
    };
    int ans = Try(1, n);
    cout << "! " << ans << '\n';
    cout.flush();
  }
}

