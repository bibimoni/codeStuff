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
const int N = (int) 5e3 + 5, LG = 17, INF = (int) 9e9;
struct Holes {
  int p, c;
};

template<class T>
struct RMQ {
  T st[LG + 1][N];
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T query(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int x[n + 2];
  Holes holes[m + 1];
  for(int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  int places = 0;
  for(int i = 1; i <= m; i++) {
    cin >> holes[i].p >> holes[i].c;
    places += holes[i].c;
  }
  if(places < n) {
    cout << "-1\n";
    return 0;
  }
  sort(x + 1, x + 1 + n);
  sort(holes + 1, holes + m + 1, [&] (Holes a, Holes b) {
    return a.p < b.p;
  });
  vector<vector<int>> dp(m + 1, vector<int>(n + 2, INF));
  dp[0][1] = 0;
  for(int i = 1; i <= m; i++) {
    int curr = 0;
    dbg(dp[i - 1]);
    for(int j = 1; j <= n + 1; j++) {
      if(dp[i][j] == INF) {
        continue;
      }
      dp[i][j] -= curr;
      curr += abs(x[j] - holes[i].p);
    }
    curr = 0;
    RMQ<int> rmq;
    rmq.build(dp[i - 1]);
    for(int j = 1; j <= n + 1; j++  ) {
      int l = max(1ll, j - holes[i].c);
      int q = (l == j + 1) ? INF : rmq.query(l, j + 1);
      dbg(q, l, j + 1);
      if(q == INF) {
        dp[i][j] = INF;
      }
      else {
        dp[i][j] = q + curr;
      }
      curr += abs(x[j] - holes[i].p);
      dbg(j, dp[i][j]);
    }
  } 
  dbg(dp);
  cout << dp[m].back();
}

