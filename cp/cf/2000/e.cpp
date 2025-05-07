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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> pre(n + 2, vector<int>(m + 2, 0));
    int w;
    cin >> w;
    vector<int> h(w);
    for (int i = 0; i < w; i++) {
      cin >> h[i];
    }
    for (int i = k; i <= n; i++) {
      for (int j = k; j <= m; j++) {
        int a = i - k + 1, b = j - k + 1, c = i, d = j;
        pre[a][b] += 1;
        pre[c + 1][b] -= 1;
        pre[a][d + 1] -= 1;
        pre[c + 1][d + 1] += 1;
      }
    }
    multiset<int, greater<int>> st;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        st.insert(pre[i][j]);
      }
    }
    sort(h.begin(), h.end());
    int ans = 0;
    for (auto c : st) {
      if (h.size()) {
        ans += c * h.back();
        h.pop_back();
      }
    }
    cout << ans << '\n';
  }
}


