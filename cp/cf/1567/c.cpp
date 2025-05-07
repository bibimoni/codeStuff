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
    int n;
    cin >> n;
    vector<int> fi, ss;
    int turn = 0;
    while (n) {
      if (!turn) {
        fi.push_back(n % 10);
      } else {
        ss.push_back(n % 10);
      }
      n /= 10;
      turn ^= 1;
    }
    auto cv = [&] (vector<int> &a) -> int {
      int ret = 0, pwr = 1;
      for (int d : a) {
        ret += d * pwr;
        pwr *= 10;
      }
      return ret;
    };
    cout << (cv(fi) + 1) * (cv(ss) + 1) - 2 << '\n';
  }
}

