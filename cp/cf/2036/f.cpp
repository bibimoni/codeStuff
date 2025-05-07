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
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r, k, id;
    cin >> l >> r >> id >> k;
    if (id == 0) {
      cout << "0\n";
      continue;
    }
    auto sum_xor = [&] (int n) -> int {
      int md = n % 4;
      if (md == 0) {
        return n;
      } else if (md == 1) {
        return 1;
      } else if (md == 2) {
        return n + 1;
      } else {
        return 0;
      }
    };
    auto range_xor = [&] (int lt, int rt) -> int {
      return sum_xor(rt) ^ sum_xor(lt - 1);
    };
    int trail = k & ((int(1) << id) - 1);
    int pre_l = (l >> id) << id;
    if ((pre_l | trail) < l) {
      pre_l = (((pre_l >> id) + 1) << id) | trail;
    } else {
      pre_l |= trail;
    }
    int pre_r = (r >> id) << id;
    if ((pre_r | trail) > r) {
      pre_r = (((pre_r >> id) - 1) << id) | trail;
    } else {
      pre_r |= trail;
    }
    pre_l >>= id;
    pre_r >>= id;
    int t = range_xor(pre_l, pre_r) << id;
    int after = (((pre_r - pre_l + 1) % 2 == 1) ? (t | trail) : t);
    cout << (range_xor(l, r) ^ after) << '\n';
  }
}


