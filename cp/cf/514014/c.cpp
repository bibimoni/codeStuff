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

const int N = (int) 5e5 + 5, LG = 20;

template<class T>
struct RMQ {
  vector<vector<T>> st;
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    st = vector<vector<T>>(LG + 1, vector<T>(N));
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
  // X a1 Y a3 .. Y .... at X (a_i > X)
  // X .... Y ... X .... Y
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, vector<int>> pos;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  RMQ<int> rmq;
  rmq.build(a);
  for(int i = 1; i <= n; i++) {
    pos[a[i]].push_back(i);
  }
  int maxLen = 0, cnt = 0;
  for(auto [v, s] : pos) {
    if(s.size() < 2)
      continue;
    for(int i = 1; i < s.size(); i++) {
      if(s[i] - s[i - 1] > 1 && rmq.query(s[i - 1] + 1, s[i] - 1) > v) {
        cnt++;
        maxLen = max(maxLen, s[i] - s[i - 1] - 1);
      }
    }
  }
  cout << cnt << ' ' << maxLen;
}

