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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0) / n;
    int curr = 0;
    bool ok = true;
    for(int i = 0; i < n; i++) {
      if(curr < 0) {
        ok = false;
        break;
      }
      if(a[i] <= sum) {
        curr -= (sum - a[i]);
      }
      else {
        curr += (a[i] - sum);
      }
    }
    cout << (ok && !curr ? "YES\n" : "NO\n");
  }
}


