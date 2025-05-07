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
  int n, a; cin >> n >> a;
  int d[n], s = 0;
  for(int i = 0; i < n; i++) cin >> d[i], s += d[i];
  if(n == 1) {
    cout << d[0] - 1;
    return 0;
  }
  for(int i = 0; i < n; i++) {
    int maxCanHave = min(d[i], a - (n - 1));
    int minCanHave = max(1ll, a - (s - d[i]));
    cout << d[i] - (maxCanHave - minCanHave + 1) << ' ';
  }
}

