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
#define double long double

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  double a[n];
  bool ok = false;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    ok |= (a[i] == 1);
  }
  if(ok) {
    cout << "1";
    return 0;
  }
  sort(a, a + n, greater<double>());
  vector<double> p(n), p1(n);
  p1[0] = (1 - a[0]);
  p[0] = a[0];
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(p[i] < p[j] * (1 - a[i]) + a[i] * p1[j]) {
        p[i] = p[j] * (1 - a[i]) + a[i] * p1[j];
        p1[i] = p1[j] * (1 - a[i]);
      }
    }
  }
  double ans = 0.0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, p[i]);
  }
  cout << fixed << setprecision(11) <<  ans;
}
 