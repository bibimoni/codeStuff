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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  map<array<int, 3>, int> cnt;
  int add = 0;
  for (int i = 0; i < n; i++) {
    int sign = (a[i] >= 0 ? 1 : -1) * (b[i] >= 0 ? 1 : -1);
    if (a[i] == 0) {
      add += b[i] == 0;
      continue;
    } 
    int m = gcd(abs(a[i]), abs(b[i]));
    cnt[{abs(b[i]) / m, abs(a[i]) / m, (a[i] == 0 || b[i] == 0 ? 1 : sign)}] += 1;
  }
  int ans = 0;
  for (const auto& [_, v] : cnt) {
    ans = max(ans, v);
  }
  cout << ans + add << '\n';
}

