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
  int n;
  cin >> n;
  auto pwr = [&] (int a, int b) -> int {
    int x = a, y = 1;
    while(b > 0) {
      if (b & 1) {
        if (y > (n + 5) / x) {
          return -1;
        }
        y *= x;
      }
      b >>= 1;
      if (b == 0) {
        break;
      }
      if (x > (n + 5) / x) {
        return -1;
      }
      x *= x;
    }
    return y;
  };
  auto sqrt_floor = [&] (int x) -> int {
    int l = 0, r = 2e9;
    while (l <= r){
      int t = (l + r) / 2;
      if (t * t > x) {
        r = t - 1;
      }
      else {
        l = t + 1;
      }
    }
    return r;
  };
  // dit me std::sqrt 
  int ans = sqrt_floor(n);
  const int MAGIC = int(2e6);
  map<int, int> was;
  auto sqrNum = [&] (int x) -> bool {
    int t = sqrt_floor(x);
    return t * t == x;
  };
  for (int j = 60; j >= 3; j--) {
    for (int i = 2; i <= int(2e6); i++) {
      int num = pwr(i, j);
      if (num == -1 || num > n) {
        break;
      }
      if(sqrNum(num)) {
        continue;
      } 
      was[num] = 1;
    }
  }
  ans += was.size();
  cout << ans << '\n';
}


