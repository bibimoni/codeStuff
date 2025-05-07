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
    int cnt2 = 0, cnt1 = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt2 += (a[i] == 2);
      cnt1 += (a[i] == 1);
    }
    if(accumulate(a + 1, a + 1 + n, 0) & 1) {
      cout << "NO\n";
      continue;
    }
    if(cnt1 % 2 != 0) {
      cout << "NO\n";
    }
    else if(cnt1 < 2 && cnt2 % 2 != 0) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
}

