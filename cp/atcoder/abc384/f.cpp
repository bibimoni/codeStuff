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

const int K = 25;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector a(n + 1, int(0));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> d(K + 5);
  for (int j = 0; j <= K; j++) {
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i++) {
      mp[a[i] % (int(1) << j)].first += 1;
      mp[a[i] % (int(1) << j)].second += a[i];
      int c = mp[(-a[i] + int(1e9) * (int(1) << j)) % (int(1) << j)].first;
      int s = mp[(-a[i] + int(1e9) * (int(1) << j)) % (int(1) << j)].second;
      d[j] += c * a[i] + s;
    }
  }

  int ans = 0;
  for (int j = 0; j <= K; j++) {
    ans += (d[j] - d[j + 1]) >> j;
  }
  cout << ans;
}

