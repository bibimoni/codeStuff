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
  int n, l, r;
  cin >> n >> l >> r;
  auto ask = [&] (int i, int j) -> int {
    assert((int(1) << i) * (j + 1) <= int(1) << n);
    cout << "? " << i << ' ' << j << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret % 100;
  };
  auto process = [&] (int bound) -> int {
    bound += 1;
    if (bound == 0) {
      return 0;
    }
    int prev = -1;
    int ret = 0;
    while (bound > 0) {
      int i = 63 - __builtin_clzll(bound);
      int j = (prev == -1 ? 0 : int(1) << (prev - i));
      (ret += ask(i, j)) %= 100;
      prev = i;
      bound -= (int(1) << i);
    }
    return ret;
  };
  int tl = process(l - 1), tr = process(r);
  cout << "! " << (tr - tl + 100) % 100;
  cout.flush();
}


