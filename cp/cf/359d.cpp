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

const int N = (int) 3e5 + 5, LG = 19;

template<class T>
struct RGCDQ {
  vector<vector<T>> st;
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    st = vector<vector<T>>(LG + 1, vector<T>(N));
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        st[j][i] = __gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T query(int l, int r) {
    int k = __lg(r - l + 1);
    return __gcd(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  RGCDQ<int> rgcdq;
  rgcdq.build(a);
  RMQ<int> rmq;
  rmq.build(a);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int retR = i, retL = i;
    //right 
    {
      int l = i, r = n;
      while(l <= r) {
        int mid = (l + r) >> 1;
        int getGcd = rgcdq.query(i, mid), getMin = rmq.query(i, mid);
        if(getMin == a[i] && getMin == getGcd) {
          l = mid + 1;
          retR = mid;
        }
        else {
          r = mid - 1;
        }
      }
    }   
    //left
    {
      int l = 1, r = i;
      while(l <= r) {
        int mid = (l + r) >> 1;
        int getGcd = rgcdq.query(mid, i), getMin = rmq.query(mid, i);
        if(getMin == a[i] && getMin == getGcd) {
          retL = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }     
    }
    ans = max(ans, retR - retL); 
  }
  vector<int> ret;
  for(int i = 1; i + ans <= n; i++) {
    int getGcd = rgcdq.query(i, i + ans), getMin = rmq.query(i, i + ans);
    if(getGcd == getMin) 
      ret.push_back(i);
  }
  cout << ret.size() << ' ' << ans << '\n';
  for(int i : ret) 
    cout << i << ' ';
}

