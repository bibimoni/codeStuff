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
    const int N = 5e4;
    vector<int> dp(N);
    int f, s;
    cin >> s >> f;
    for (int i = f - 1; i >= 1; i--) {
      dp[i] = dp[i + 1] + 1;
    }
    for (int i = f + 1; i < N; i++) {
      dp[i] = dp[i - 1] + 1;
    }
    auto get = [&] (int x) -> vector<int> {
      vector<int> extract;
      vector<int> ret;
      int tmp = x;
      while (tmp) {
        extract.push_back(tmp % 10);
        tmp /= 10;
      }
      sort(extract.begin(), extract.end());
      do {
        int num = 0;
        for (int j : extract) {
          num = num * 10 + j;
        }
        if (num != x)
          ret.push_back(num);
      } while (next_permutation(extract.begin(), extract.end()));
      return ret;
    };
    dp[0] = N;
    for (int i = 1; i < N; i++) {
      auto p = get(i);
      for (int num : p) {
        dp[num] = min(dp[num], dp[i] + 1);  
      }
    }
    int ans = 1;
    int curr = s;
    set<int> vis;
    vis.insert(s);
    while (true) {
      // A
      vector<int> go = get(curr);
      if (curr <= 9999)
        go.push_back(curr + 1);
      int nxt = 0;
      for (int j : go) {
        if (dp[nxt] > dp[j] && vis.find(j) == vis.end()) {
          nxt = j;
        }
      }      
      if (nxt == 0) {
        cout << -1 << '\n';
        break;
      }
      curr = nxt;
      vis.insert(curr);
      dbg(curr);
      if (dp[curr] == 0) {
        cout << ans << '\n';
        break;
      }
      // B
      go = get(curr);
      if (curr <= 9999)
        go.push_back(curr + 1);
      if (go.size() <= 1 && (go.size() == 1 && go.back() == f)) {
        cout << -1 << '\n';
        break;
      }
      nxt = 0;
      dbg(go);
      for (int j : go) {
        dbg(dp[nxt], dp[j], j, vis);
        if (j != f && dp[nxt] > dp[j] && vis.find(j) == vis.end()) {
          nxt = j;
        }
      }
      dbg(nxt);
      if (nxt == 0) {
        cout << -1 << '\n';
        break;
      }
      dbg(curr);
      curr = nxt;
      vis.insert(curr);
      ans++;
    }
  }
}


