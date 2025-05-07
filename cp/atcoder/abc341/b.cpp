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
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int s[n + 1], t[n + 1];
  for(int i = 1; i < n; i++) {
    cin >> s[i] >> t[i];
  }
  for(int i = 1; i < n; i++) {
    a[i + 1] += (a[i] / s[i]) * t[i];
  }
  cout << a[n];
}


