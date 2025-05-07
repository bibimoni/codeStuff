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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    vector<int> p(3);
    cin >> p[0] >> p[1] >> p[2];
    sort(p.begin(), p.end());
    cout << p[2] - p[0] << '\n';
  }
}


