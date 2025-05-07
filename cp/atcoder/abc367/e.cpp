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
  int n, k;
  cin >> n >> k;
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int LG = 61;
  vector<vector<int>> lift(n + 1, vector<int>(LG));

  for (int i = 1; i <= n; i++) {
    lift[i][0] = x[i];
  }
  for (int j = 1; j < LG; j++) {
    for(int i = 1; i <= n; i++) {
      lift[i][j] = lift[lift[i][j - 1]][j - 1];
    }
  }
  vector<int> ans = a;
  for (int i = 1; i <= n; i++) {
    int cur = i;
    for (int j = LG - 1; j >= 0; j--) {
      if ((k >> j) & 1) {
        cur = lift[cur][j];
      }
    }
    ans[i] = a[cur];
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}


