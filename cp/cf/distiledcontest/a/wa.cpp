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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k; cin >> n >> k;
    int a[n]; 
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    if(a[0] > k) {
      cout << "YES\n1\n";
      continue;
    }
    else if(n == 1) {
      cout << "NO\n";
      continue;
    }
    int sum = a[0] + a[1];
    if(sum >= k) {
      cout << "YES\n2\n";
    }
    else {
      cout << "NO\n";
    }
  }
}

