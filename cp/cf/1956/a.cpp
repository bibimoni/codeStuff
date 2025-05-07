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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    for(int i = 0; i < k; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    while(q--) {
      int n;
      cin >> n;
      while(a[0] <= n) {
        for(int i = 0; i < k; i++)
          if(a[i] <= n)
            n--;
      }
      cout << n << ' ';
    }
    cout << '\n';
  }
}

