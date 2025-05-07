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
  vector<int> pwr3;
  for (int cur = 1; cur <= int(1e6);) {
    pwr3.push_back(cur);
    cur *= 3;
  }
  vector<int> calc3(int(1e6) + 5, 0);
  for (int cur = 1; cur <= int(1e6); cur++) {
    calc3[cur] = calc3[cur / 3] + 1;
  }
  vector<int> p(int(1e6) + 5, 0);
  for (int i = 1; i <= int(1e6); i++) {
    p[i] = p[i - 1] + calc3[i];
  }
  // dbg(calc3);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    int start = r;
    int cur = l;
    for (int i = l; i <= r; i++) {
      auto step = calc3[i];
      if (step <= start) {
        start = step;
        cur = i;
      } else {
        break;
      }
    }
    int ans = start;
    ans -= calc3[cur];
    ans += p[r] - p[l - 1];
    for (int i = l; i <= r; i++) {
      if (i == cur) {
        continue;
      }
      int tobe = i;
      tobe = tobe * pwr3[start];
      int cur = 0;
      while (tobe) {
        tobe /= 3;
        cur += 1;
      }
      ans += cur;
      ans -= calc3[i];
      break;
    }
    cout << ans << '\n';
  }
}


