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
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> d(n);
  for(int i = 0; i < n; i++) {
    cin >> d[i];
    d[i]--;
  }
  sort(d.begin(), d.end());
  for(int i = 1; i < n; i++) {
    (d[i] -= d[0]) %= (a + b);
  }
  d[0] = 0;
  sort(d.begin(), d.end());
  bool ok = d[n - 1] - d[0] + 1 <= a;
  for(int i = 0; i < n; i++) {
    (d[i] += (a - 1)) %= (a + b);
  }
  sort(d.begin(), d.end());
  ok |= d[n - 1] - d[0] + 1 <= a;
  cout << (ok ? "Yes\n" : "No\n");
}


