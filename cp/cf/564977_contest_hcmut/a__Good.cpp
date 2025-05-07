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

string sub3(int n, int m, vector<string> &a) {
  string ans = "";
  if (m == 1) {
    return string(1, a[1][1]) + string(1, a[2][1]);
  }
  int idx = m;
  for (int j = 1; j < m; j++) {
    if (a[1][j + 1] > a[2][j]) {
      idx = j;
      break;
    }
  }
  for (int j = 1; j <= idx; j++) {
    ans += a[1][j];
  }
  for (int j = idx; j <= m; j++) {
    ans += a[2][j];
  }
  return ans;
}
 
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  if (n == 2) {
    cout << sub3(n, m, a);
    return 0;
  }
  map<pair<int, int>, string> f; 
  auto dfs = [&] (auto &&self, int i, int j) -> string {
    if (i == n && j == m) {
      return string(1, a[i][j]);
    }
    if (f.count({i, j})) {
      return f[{i, j}];
    }
    string ans;
    if (i == n) {
      ans = a[i][j] + self(self, i, j + 1);
    } else if (j == m) {
      ans = a[i][j] + self(self, i + 1, j);
    } else {
      string str1 = self(self, i, j + 1);
      string str2 = self(self, i + 1, j);
      if (str1 < str2) {
        ans = a[i][j] + str1;
      } else {
        ans = a[i][j] + str2;
      }
    }
    return f[{i, j}] = ans;
  };
  cout << dfs(dfs, 1, 1);
}