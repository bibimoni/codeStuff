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

vector<int> z_function(const string& s) {
  int n = (int) s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
      z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  const int INF = (int) 2e9;
  vector<int> dp(n, INF);
  dp[0] = a;
  for(int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + a;
    string t = s.substr(0, i + 1);
    reverse(t.begin(), t.end());
    auto zfunc = z_function(t);
    reverse(zfunc.begin(), zfunc.end());
    for(int j = 0; j < i; j++) {
      int l = zfunc[j];
      if(l > 0 && i - l >= j) {
        dp[i] = min(dp[i], dp[i - l] + b);
      }
    }
  } 
  cout << dp[n - 1] << '\n';
}