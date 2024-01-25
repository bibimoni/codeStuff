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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int minE = *min_element(a, a + n), idxM;
    for(int i = 0; i < n; i++) if(a[i] == minE) {idxM = i; break;}
    bool check = true;
    for(int i = idxM; i < n - 1; i++) {
      if(a[i] > a[i + 1]) {
        check = false; break;
      }
    }
    if(!check) {
      cout << "-1\n";
    }
    else {
      cout << idxM << '\n';
    }
  }
}


