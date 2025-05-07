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
  for (int tc = 1; tc <= tt; tc++) {
    int a, b, m;
    cin >> a >> b >> m;
    int ret = 0;
    for (int num = a; num <= b; num++) {
      vector<int> f;
      if (num % m != 0) {
        continue;
      }
      int tmp = num;
      while (tmp) {
        f.push_back(tmp % 10);
        tmp /= 10;
      }
      int half = (f.size() + 1) / 2;
      bool ok = true;
      for (int i = 1; i < half; i++) {
        ok &= f[i - 1] != 0 && f[i] != 0;
        ok &= f[i - 1] <= f[i];
      }
      for (int i = half - 1; i < f.size() - 1; i++) {
        ok &= f[i] >= f[i + 1];
        ok &= f[i + 1] != 0;
      }
      if (f.size() >= 3) {
        ok &= f[half - 1] != f[half] && f[half - 1] != f[half - 2];
      }
      if (f.size() % 2 == 0) {
        continue;
      }
      if (ok) {
        ret += 1;
        // dbg(num);
      }
    }
    cout << "Case #" << tc << ": " << ret << '\n';  
  }
}

