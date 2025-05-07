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
    int n, k;
    cin >> n >> k;
    if(n == 1) {
      cout << k << '\n';
      continue;
    }
    int desired = 0;
    int mark = 0;
    for(int j = 60; j >= 0; j--) {
      if((k >> j) & 1) {
        mark = j;
        desired = (1 << j) - 1;
        break;
      }
    }
    desired = (__builtin_popcountll(k) > desired ? k : desired);
    cout << desired << ' ';
    cout << k - desired << ' ';
    vector<int> ans(n - 2, 0);
    for(int i : ans)
      cout << i << ' ';
    cout << '\n';
  }
}


