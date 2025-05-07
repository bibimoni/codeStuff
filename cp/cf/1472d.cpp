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
    int n;
    cin >> n;
    int a[n + 1];
    int alice = 0, bob = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for(int i = 1; i <= n; i++) {
      if(i & 1) {
        if(a[i] % 2 == 0) {
          alice += a[i];
        }
      }
      else {
        if(a[i] % 2 != 0) {
          bob += a[i];
        }
      }
    }
    if(alice > bob) {
      cout << "Alice\n";
    }
    else if(bob > alice) {
      cout << "Bob\n";
    }
    else {
      cout << "Tie\n";
    }
  }
}

