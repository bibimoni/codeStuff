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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if(a == b) {
      cout << "0\n";
      continue;
    }
    if(abs(a - b) >= x) {
      cout << "1\n";
      continue;
    }
    vector<int> pos = {a + x, b + x, a - x, b - x};
    bool ok = false;
    for(auto p : pos) {
      if(l <= p && p <= r && abs(a - l) >= x && abs(b - l) >= x) {
        cout << "2\n";
        ok = true;
        break;
      }
      if(l <= p && p <= r && abs(a - r) >= x && abs(b - r) >= x) {
        cout << "2\n";
        ok = true;
        break;
      }
    }
    if(ok) {
      continue;
    }
    if(abs(l - r) >= x) {
      if(abs(a - l) >= x && abs(r - b) >= x) {
        cout << "3\n";
        continue;
      }
      if(abs(a - r) >= x && abs(l - b) >= x) {
        cout << "3\n";
        continue;
      }
    }
    cout << "-1\n";
  }
}


