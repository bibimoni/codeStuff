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

const int N = (int) 2e3 + 5, LG = 17;

template<class T>
struct RMQ {
  T st[LG + 1][N];
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a[n + 1];
  RMQ<int> rmq[m + 1];
  for(int i = 1; i <= n; i++) {
    a[i].resize(m + 1);
    for(int j = 1; j <= m; j++)
      cin >> a[i][j];      
  }
  for(int i = 1; i <= m; i++) {
    vector<int> tmp(n + 1);
    for(int j = 1; j <= n; j++) {
      tmp[j] = a[j][i];
    }
    rmq[i].build(tmp);
  }
  int ans = 0;
  vector<int> shots(m + 1, 0);
  for(int i = 1; i <= n; i++) {
    int l = i, r = n, ret = -1;
    vector<int> tmp(m + 1, 0);
    while(l <= r) {
      int mid = (l + r) >> 1;
      int tot = 0;
      vector<int> tmp1(m + 1, 0);
      for(int j = 1; j <= m; j++) {
        int u = rmq[j].query(i, mid);
        tot += u;
        tmp1[j] = u;
      }
      if(tot <= k) {
        ret = mid;
        tmp = tmp1;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    if(ret != -1 && ret - i + 1 >= ans) {
      ans = ret - i + 1;
      shots = tmp;
    }
  }
  for(int j = 1; j <= m; j++) {
    cout << shots[j] << ' ';
  }
}