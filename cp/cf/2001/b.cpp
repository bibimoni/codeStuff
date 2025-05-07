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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << "-1\n";
      continue;
    }
    vector<int> p(n);
    iota(p.begin(),p.end(), 1);
    reverse(p.begin(), p.begin() + (n / 2) + 1);
    for (int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
}


