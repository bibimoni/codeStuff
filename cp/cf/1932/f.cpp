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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(m);
    vector<int> cnt(n + 2, 0);
    for(int i = 0; i < m; i++) {
      cin >> a[i][0] >> a[i][1];
      cnt[a[i][0]]++;
      cnt[a[i][1] + 1]--;
    }
    sort(a.begin(), a.end(), [&] (array<int, 2> i, array<int, 2> j) {
      return i[1] < j[1];
    });
    vector<int> dp(n + 1, 0);
    vector<int> preMax(n + 1, 0);
    vector<int> left(m + 1, n + 1);
    for(int i = m - 1; i >= 0; i--) {
      left[i] = min(a[i][0], left[i + 1]);
    }
    int id = 0;
    for(int i = 1; i <= n; i++) {
      cnt[i] += cnt[i - 1];
      while(a[id][1] < i && id + 1 <= m)
        id++;
      dp[i] = cnt[i];
      if(left[id] <= i)
        dp[i] += preMax[left[id] - 1];
      preMax[i] = max(preMax[i - 1], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}

