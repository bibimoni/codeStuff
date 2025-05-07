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
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int total = accumulate(a.begin(), a.end(), 0ll);
    if(sqrt(total) == (int) sqrt(total)) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}


