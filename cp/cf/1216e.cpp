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
    int k;
    cin >> k;
    int n = 1;
    string curr = "";
    auto digits = [&] (int x) -> int {
      int ret = 0;
      for(; x; x /= 10, ret++);
      return ret;
    };
    while(curr.size() < k) {
      k -= curr.size();
      curr += to_string(n);
      n++;
    }
    cout << curr[k - 1] << '\n';
  }
}

