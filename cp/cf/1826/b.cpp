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
    int a[n];
    for(int &i : a) {
      cin >> i;
    }
    vector<int> neg;
    for(int i = 0; i < n - i; i++) {
      neg.push_back(abs(a[i] - a[n - i - 1]));
    }
    dbg(neg);
    int gcd = neg[0];
    for(int i = 1; i < neg.size(); i++) {
      gcd = __gcd(neg[i], gcd);
    }
    cout << gcd << '\n';
  }
}


