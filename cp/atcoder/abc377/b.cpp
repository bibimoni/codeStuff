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
  const int N = 8;
  vector<string> a(N);
  vector<int> row(N), col(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    for (int j = 0; j < int(a[i].size()); j++) {
      if (a[i][j] == '#') {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans += !row[i] && !col[j];
    }
  }
  cout << ans;
}


