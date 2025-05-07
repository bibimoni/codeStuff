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
  freopen("CANDIES.INP", "r", stdin);
  freopen("CANDIES.OUT", "w", stdout);
  int n;
  cin >> n;
  int a[n];
  int total = 0, eat = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] % 3 == 0 && a[i] > 0) {
      total += a[i];
      eat++;
    }
  }
  cout << eat << '\n' << (total - 3 * eat) / 3;

}


