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
#define int            long long

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  a[n] = {0, 0};
  sort(a.begin(), a.end(), [&] (pair<int, int> i, pair<int, int> j) {
    return max(i.first, i.second) < max(j.first, j.second);
  });
  auto mahattan = [&] (pair<int, int> a, pair<int, int> b) -> int {
    return abs(a.first - b.first) + abs(a.second - b.second);
  };
  auto get = [&] (pair<int, int> i) -> int {
    return max(i.first, i.second);
  };
  vector<vector<pair<int, int>>> group;
  for(int i = 1; i <= n; i++) {
    vector<pair<int, int>> tmp;
    tmp.push_back(a[i]);
    int j = i + 1;
    while(j <= n && get(a[i]) == get(a[j])) {
      tmp.push_back(a[j]);
      j++;
    }
    group.push_back(tmp);
    i = j - 1;
  }
  vector<array<int, 2>> dp(group.size() + 1, {{INF, INF}});
  dp[0] = {0, 0};
  pair<int, int> lastTop = {0, 0}, lastBack = {0, 0};
  int i = 0;
  dbg(group);
  for(auto &p : group) {
    i++;
    pair<int, int> back = *min_element(p.begin(), p.end(), [&] (pair<int, int> i, pair<int, int> j) {
      if(i.first != j.first) {
        return i.first < j.first;
      }
      else {
        return i.second > j.second;
      }
    });
    pair<int, int> top = *min_element(p.begin(), p.end(), [&] (pair<int, int> i, pair<int, int> j) {
      if(i.second != j.second) {
        return i.second < j.second;
      }
      else {
        return i.first > j.first;
      }
    });
    dp[i][0] = min(dp[i][0], dp[i - 1][0] + mahattan(lastBack, top) + mahattan(back, top));
    dp[i][0] = min(dp[i][0], dp[i - 1][1] + mahattan(lastTop, top) + mahattan(back, top));
    dp[i][1] = min(dp[i][1], dp[i - 1][0] + mahattan(lastBack, back) + mahattan(back, top));
    dp[i][1] = min(dp[i][1], dp[i - 1][1] + mahattan(lastTop, back) + mahattan(back, top));
    lastTop = top;
    lastBack = back;
  }
  cout << min(dp[group.size()][0], dp[group.size()][1]);
}
