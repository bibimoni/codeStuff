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
  int n;
  cin >> n;
  auto in = [&] () -> vector<string> {
    vector<string> ret(n);
    for(int i = 0; i < n; i++) {
      cin >> ret[i];
    }
    return ret;
  };
  auto a = in();
  auto b = in();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[i][j]) {
        cout << i + 1 << ' ' << j + 1;
      }
    }
  }
}


