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

const int N = (int) 2e5 + 5, LG = 17;
template<class T>
struct RMQ {
  vector<vector<T>> st;x
  int n;
  void build (const vector<T> &a) {
    st = vector<vector<T>>(LG + 1, vector<T>(N));
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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    RMQ<int> rmq;
    rmq.build(a);
    int ans = n - 2;
    int k = n;
    for(int i = 1; i <= k - 1; i++) {
      int j = i;
      while(k - j + 1 > 2 && (rmq.query(j + 1, k) >= a[j] || rmq.query(j, k - 1) >= a[k])) {
        if(rmq.query(j + 1, k) >= a[j])
          j++;
        if(rmq.query(j, k - 1) >= a[k])
          k--;
      }
      dbg(i, j, k);
      if(k - j + 1 <= 2) {
        ans = i - 1;
        break;
      }
      else {
        i = max(j - 1, i);
      }
    }
    cout << ans << '\n';
  }
}

