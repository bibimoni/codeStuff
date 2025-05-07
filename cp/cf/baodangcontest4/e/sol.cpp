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

vector<vector<long double>> dp;

long double Try(int i, int n, int cnt, int k, vector<int> &a, vector<int> &b, vector<long double> &p) {
  if(i == n) {
    return 0.0;
  }
  if(dp[i][cnt] != (long double) -1) {
    return dp[i][cnt];
  }
  bool doub = (cnt == k);
  long double t1 = a[i] * (doub ? 2 : 1) * p[i] - b[i] * (1.0 - p[i])
    + Try(i + 1, n, (doub ? 1 : cnt + 1), k, a, b, p);
  long double t2 = Try(i + 1, n, (doub ? 0 : cnt), k, a, b, p);
  return (dp[i][cnt] = max(t1, t2));
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  dp = vector<vector<long double>>(n, vector<long double>(k + 1, -1));
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
  cout << setprecision(9) << Try(0, n, 0, k, a, b, p);
}

