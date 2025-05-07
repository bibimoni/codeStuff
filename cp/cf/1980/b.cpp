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
    int n, f, k;
    cin >> n >> f >> k;
    f--;
    k--;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int val = a[f];
    sort(a.begin(), a.end(), greater<int>());
    bool can = false;
    for(int i = 0; i <= k; i++) {
      if(a[i] == val) {
        can = true;
      }
    }
    bool maybe = false;
    for(int i = k + 1; i < n; i++) {
      if(a[i] == val) {
        maybe = (true && can);
      }
    }
    if(maybe) {
      cout << "MAYBE\n";
    }
    else {
      cout << (can ? "YES\n" : "NO\n");
    }
  }
}


