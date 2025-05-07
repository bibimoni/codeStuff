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
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int curr = 0;
    bool alice = true;
    n = a.size();
    for(int i = 0; i < n - 1; i++) {
      int prev = a[i];
      a[i] -= curr;
      if(a[i] == 1) {
        alice = !alice;
      }
      else {
        break;
      }
      curr = prev;
    }     
    cout << (alice ? "Alice\n" : "Bob\n");
  }
}


