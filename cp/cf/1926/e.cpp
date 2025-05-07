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
    int n, k;
    cin >> n >> k;
    int base = (n + 1) / 2;
    int curr = base;
    if(base >= k) {
      cout << 2 * k - 1 << '\n';
      continue;
    }
    int cnt = 1;
    int add = base / (cnt * 2);
    if((2 * (add + 1) - 1) * (cnt * 2) <= n) 
      add++;
    while(curr + add < k) {
      curr += add;
      cnt *= 2;
      add = base / (cnt * 2);
      if((2 * (add + 1) - 1) * (cnt * 2) <= n) 
        add++;
    }
    k -= curr;
    cout << (2 * k - 1) * (cnt * 2) << '\n';
  }
}

