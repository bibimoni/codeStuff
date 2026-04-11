/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> ans;
  vector<set<int>> cnt(n + 1);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    cnt[a].insert(b);
    if (cnt[a].size() == m) {
      ans.push_back(a);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
}
