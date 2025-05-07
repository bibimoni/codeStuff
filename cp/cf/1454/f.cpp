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
//can't run on local machine, reduce the constant 'N'
const int INF = (int) 1e18, N = (int) 2e5 + 5, LG = 17;
template<class T>
struct RMQ {
  vector<vector<T>> st = vector<vector<T>>(LG + 1, vector<T>(N));
  // T st[LG + 1][N];  
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T queryMin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
  T queryMax(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
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
    vector<int> suf(n + 2, 0), pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pref[i] = max(pref[i - 1], a[i]);
    }
    RMQ<int> rmq; 
    rmq.build(a);
    for(int i = n; i >= 1; i--) {
      suf[i] = max(suf[i + 1], a[i]);
    }
    auto findRight = [&] (int id, int value) {
      int l = id, r = n, ret = -1;  
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(value >= suf[mid]) {
          ret = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      return ret;
    };
    auto findLeft = [&] (int id, int right, int value) {
      int l = right - 1, r = n - 1, ret = -1;
      while(l <= r) {
        int mid = (l + r) >> 1;
        int t = rmq.queryMin(id, mid);
        if(t >= value && suf[mid + 1] == value) {
          l = mid + 1;
          if(t == value) {
            ret = mid;
            break;
          }
        }
        else {
          r = mid - 1;
        }
      }
      return ret;
    };
    array<int, 3> ans({-1, -1, -1});
    for(int i = 1; i <= n - 2; i++) {
      int right = findRight(i + 2, pref[i]);
      if(right == -1) {
        continue;
      }
      int left = findLeft(i + 1, right, pref[i]);
      if(left == -1) {
        continue;
      }
      ans = {i, left - i, n - left};
      break;
    }
    if(ans == array<int, 3>({-1, -1, -1})) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  }
}
