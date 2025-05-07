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
  vector<int> ans(501);
  ans[1] = 1;
  for(int i = 2; i <= 500; i++) {
    ans[i] = ans[i - 1] + 2 * i * i - i;
  }
  while(tt--) {
    int n;
    cin >> n;
    cout << ans[n] << ' ' << 2 * n << '\n';
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    reverse(p.begin(), p.end());
    for(int i = 0; i < n; i++) {
      for(int j = 1; j <= 2; j++) {
        cout << j << ' ' << i + 1 << " ";
        for(int pi : p)
          cout << pi + 1 << ' ';
        cout << '\n';
      }
    }
  }
}

