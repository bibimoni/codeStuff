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
  int xh, yh, xu, yu;
  int n; 
  cin >> xh >> yh >> xu >> yu >> n;
  int a[n], b[n], c[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  int at = yu - yh, bt = xh - xu, ct = at * (-xh) + bt * (-yh);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    double xi = (ct * b[i] - bt * c[i]) / ((double) bt * a[i] - at * b[i]);
    double yi = (at * c[i] - ct * a[i]) / ((double) bt * a[i] - at * b[i]);
    if(min(xh, xu) <= xi && xi <= max(xh, xu) && min(yh, yu) <= yi && yi <= max(yh, yu)) {
      ans++;
    }
  }
  cout << ans;
}

