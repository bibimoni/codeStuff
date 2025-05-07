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
int n, a, x, y;
map<int, long double> f;
long double Try(int n) {
  if(n == 0)
    return 0.0;
  if(f.count(n))
    return f[n];
  long double firstValue = Try(n / a) + x;
  long double secondValue = 0.0;
  for(int i = 2; i <= 6; i++) {
    secondValue += (Try(n / i) + y) / 6.0;
  }
  secondValue += y / 6.0;
  secondValue *= 6.0 / 5.0;
  // dbg(n, firstValue, secondValue);
  return (f[n] = (secondValue < firstValue ? secondValue : firstValue));
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> a >> x >> y;
  long double ans = Try(n);
  cout << fixed << setprecision(10) << ans;
}


