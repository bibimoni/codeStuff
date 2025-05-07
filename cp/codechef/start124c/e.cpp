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
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> b(n);
    for(int i = l; i <= r; i += 2) {
      b[i - l] = i + 1;
      if(n % 2 == 0 || i < r) 
        b[i - l + 1] = i;
    }
    if(n & 1) {
      b[n - 1] = r;
      swap(b[n - 1], b[n - 2]);
    }
    int curr = l;
    bool ok = true;
    for(int i : b) {
      if(__gcd(curr++, i) != 1) {
        cout << "-1\n";
        ok = false;
        break;
      }
    }
    if(!ok)
      continue;
    for(int i : b) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}


