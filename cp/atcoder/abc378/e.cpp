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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto b = a;
  sort(b.begin() + 1, b.end());
  int ans = 0;
  for (int i = 1; i <= n; i++) {

  }
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i] * i;
    ans += cur;
  }
}


