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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long double> p(n);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int cnt = 0;
  long double ans = 0.0;
  for (int i = 0; i < n; i++) {
    int c = (cnt == k ? 2 : 1);
    long double cur = c * a[i] * p[i] - (1.0 - p[i]) * b[i];
    if (cnt == k) {
      cnt = 0;
    }
    if (cur >= 0) { 
      ans += cur;
      cnt += 1;
    }
  }
  cout << setprecision(9) <<  ans << '\n';
}

