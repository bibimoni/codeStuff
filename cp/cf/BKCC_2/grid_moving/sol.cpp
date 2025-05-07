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

const int LG = 20; 

template<class T>
struct RMQ {
  vector<vector<T>> st;
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    st = vector<vector<T>>(LG + 1, vector<T>(n + 5));
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
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int sum = 0, acc = a[1];
    for (int i = 2; i <= n; i++) {
      sum += (i - 1) * a[i] + acc;
      acc += a[i];
    }

    RMQ<int> rmq;
    rmq.build(a);
    int sum_mn = 0;
    for (int i = 1; i <= n; i++) {
      int lo = 1, hi = i, rl = i;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (rmq.query(mid, i) >= a[i]) {
          hi = mid - 1;
          rl = mid;
        } else {
          lo = mid + 1;
        }
      }
      lo = i, hi = n; 
      int rr = i;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (rmq.query(i ,mid) >= a[i]) {
          lo = mid + 1;
          rr = mid;
        } else {
          hi = mid - 1;
        }
      }
      sum_mn += ((i - rl + 1) * (rr - i + 1) - 1) * a[i];
    }  
    cout << sum - 2 * sum_mn << '\n';
  }
}


