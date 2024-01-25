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

int p, a, b, c, d, n;
double calc(int i) {
  return p * (sin(a * i + b) + cos(c * i + d) + 2);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> p >> a >> b >> c >> d >> n;
  double prices[n];
  for(int i = 1; i <= n; i++) prices[i] = calc(i);
  double currMax = 0.0, ans = 0.0;
  for(int i = 1; i <= n; i++) {
    currMax = max(currMax, prices[i]);
    ans = max(ans, currMax - prices[i]);
  }
  cout << fixed << setprecision(6) << ans;
}

