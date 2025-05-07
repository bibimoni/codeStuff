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
    int n;
    cin >> n;
    vector<int> x(n - 1);
    for(int i = 0; i < n - 1; i++) {
      cin >> x[i];
    }
    vector<int> a(n, 1e6);
    for(int i = 1; i < n; i++) {
      a[i] = a[i - 1] + x[i - 1];
    }
    for(int i : a) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}


