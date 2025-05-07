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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("DAYSO.inp", "r", stdin);
  freopen("DAYSO.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> a(n);
  a[0] = b[0];
  int sum = a[0];
  for (int i = 1; i < n; i++) {
    a[i] = (i + 1) * b[i] - sum;
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}


