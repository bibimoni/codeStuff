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
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int x;
      cin >> x;
      x -= 1;
      a[i].push_back(x);
    }
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    if (cur < j) {
      swap(cur, j);
    }
    cur = a[cur][j];
  }
  cout << cur + 1<< '\n';
}


