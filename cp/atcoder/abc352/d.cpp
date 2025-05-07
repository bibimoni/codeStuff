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

const int LG = 18;

template<class T>
struct RMQ {
  vector<vector<T>> st;
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    st = vector<vector<T>>(LG + 1, vector<T>(n + 1));
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

template<class T>
struct RMQM {
  vector<vector<T>> st;
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    st = vector<vector<T>>(LG + 1, vector<T>(n + 1));
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T query(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
  }
};


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int k, n;
  cin >> n >> k;
  vector<pair<int, int>> p(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(p.begin() + 1, p.end(), [&] (pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
  });
  vector<int> t(n + 1);
  for(int i = 1; i <= n; i++) {
    t[i] = p[i].second;
  }
  RMQ<int> minQ;
  minQ.build(t);
  RMQM<int> maxQ;
  maxQ.build(t);
  int ans = n;
  for(int i = k; i <= n; i++) {
    ans = min(ans, maxQ.query(i - k + 1, i) - minQ.query(i - k + 1, i));
  }
  cout << ans;
}


