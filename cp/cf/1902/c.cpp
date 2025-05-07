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
const int N = (int) 2e6 + 5;
int a[N];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];  
    }
    if(n == 1) {
      cout << "1\n";
      continue;
    }
    sort(a + 1, a + n + 1);
    int gap = a[2] - a[1];  
    for(int i = 3; i <= n; i++) {
      gap = __gcd(gap, a[i] - a[i - 1]);
    }
    int ans = 0;
    for(int i = 1; i < n; i++) {
      ans += (a[n] - a[i]) / gap;
    }
    int e = a[n] - gap; ans++;
    for(int i = n - 1; i >= 1; i--) {
      if(e == a[i]) ans++, e -= gap;
      else break;
    }
    cout << ans << '\n';
  }
}


