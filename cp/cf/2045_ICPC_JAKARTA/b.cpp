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
  int n, d, s;
  cin >> n >> d >> s;
  // int ans = max(s, step * 2 * s);
  int ans = s;
  if (s <= d && 2 * s <= n) {
    ans = 2 * s;
  }
  for (int del = 2; del * del <= n; del++) {
    int step = min(n / (del * s), d / ((del - 1) * s));
    // dbg(step, del, s);
    ans = max(ans, step * del * s);
    int ndel = n / del;
    step = min(n / (ndel * s), d / ((ndel - 1) * s));
    // dbg(step, ndel, s);
    ans = max(ans, step * ndel * s);
  } 
  int del = n;
  int step = min(n / (del * s), d / ((del - 1) * s));
  // dbg(step, del, s);
  ans = max(ans, step * del * s);

  cout << ans << '\n';
}

