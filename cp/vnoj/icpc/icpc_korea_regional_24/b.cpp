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
  vector<array<int, 2>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1];
  }
  deque<array<int, 3>> dq;
  dq.push({1, 0, 1});
  dq.push({1, 1, 1});
  while
}

