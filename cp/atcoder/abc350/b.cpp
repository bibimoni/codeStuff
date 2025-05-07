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
  int n, q;
  cin >> n >> q;
  vector<int> mark(n + 1, 1);
  for(int i = 0; i < q; i++) {
    int t;
    cin >> t;
    mark[t] ^= 1;
  }
  cout << accumulate(mark.begin(), mark.end(), -1ll);
}


