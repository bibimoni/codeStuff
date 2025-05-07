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
  int n, k; cin >> n >> k;
  map<int, int> idx;
  int a[n + 1], p = 0, q = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(idx[2 * k - a[i]] != 0) {
      p = idx[2 * k - a[i]], q = i;
    }
    idx[a[i]] = i;
  }
  cout << p << ' ' << q;
}


