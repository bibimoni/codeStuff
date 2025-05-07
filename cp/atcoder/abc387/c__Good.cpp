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
  int l, r;
  cin >> l >> r;
  auto ok = [&] (int x) {
    vector<int> ret;
    while (x) {
      ret.push_back(x % 10);
      x /= 10;
    }
    bool v = true;
    for (int i = 0; i < ret.size() - 1; i++) {
      v &= ret[i] < ret[ret.size() - 1];
    }
    return int(v);
  };
  int ans = 0;
  auto calc = [&] (int num) -> int {
    int ret = 0;
    for (int i = 10; i <= num; i++) {
      ret += ok(i);
    }
    return ret;
  };
  int rr = calc(r);
  int l1 = calc(l - 1);
  cout << rr << ' ' << l1;
}

