#include<bits/stdc++.h>
using namespace std;

#define int int64_t 

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n > 0) {
      int cur = 1;
      while (cur * k <= n && k > 1) {
        cur *= k;
      }
      n -= cur;
      ans += 1;
    }
    cout << ans << '\n';
  }
}


