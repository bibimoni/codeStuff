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

#define int            long long
#define all(x)         x.begin(), x.end()
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  int vertical[n + 1]; vector<int> horizontal;
  for(int i = 0; i < n; i++) cin >> vertical[i];
  for(int i = 0, x1, x2, y; i < m; i++) {
    cin >> x1 >> x2 >> y;
    if(x1 == 1)
      horizontal.emplace_back(x2);
  }
  int j = 0;
  vertical[n] = (int) 1e9;
  sort(vertical, vertical + n + 1);
  sort(all(horizontal)); m = horizontal.size();
  int ans = INF;
  for(int i = 0; i <= n; i++) {
    while(j < m && horizontal[j] < vertical[i]) j++;
    ans = min(ans, i + m - j);
  }
  cout << ans;
}

