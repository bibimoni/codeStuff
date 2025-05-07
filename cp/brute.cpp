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

bool is_palin(int num) {
  int t = num, t_rev = 0;
  while (num) {
    t_rev = t_rev * 10 + num % 10;
    num /= 10;
  }
  return t == t_rev;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for (int k = 1; k < 10; k++) {
    int best = 0;
    for (int i = 99; i >= 10; i--) {
    // for (int i = 999; i >= int(1e2); i--) {
    // for (int i = 99999; i >= int(1e4); i--) {
    // for (int i = 999999; i >= int(1e5); i--) {
    // for (int i = 9999999; i >= int(1e6); i--) {
    // for (int i = 999999999; i >= int(1e8); i--) {
      if (is_palin(i) && i % k == 0) {
        best = max(i, best);
        break;
      }
    } 
    dbg(k, best);
  }
}

