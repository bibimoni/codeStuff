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

const int N = 2e5 + 5;
int a[N];

struct fenwick {
  int ft[N];
  void init() {
    memset(ft, 0, sizeof ft);
  }
  int __get(int id) { 
    int ans = 0;
    for(; id > 0; id -= (id & -id)) ans += ft[id];
    return ans;
  }
  void update(int id, int del) {
    for(; id < N; id += (id & -id)) ft[id] += del;
  }
  int get(int l, int r) {
    return __get(r) - (l == 1 ? 0 : __get(l - 1));
  }
};

fenwick pre, dp[10];

bool hasNum(int num, int c) {
  while(num) {
    if(c == num % 10) return true;
    num /= 10;
  }
  return false;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q; cin >> n >> q;
  pre.init();
  for(int j = 1; j <= 9; j++) dp[j].init();
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    pre.update(i, a[i]);
    for(int j = 1; j <= 9; j++) {
      if(i % j == 0 || hasNum(i, j)) 
        dp[j].update(i, a[i]);
    }
  }

  while(q--) {
    int type; cin >> type;
    if(type == 1) {
      int i, c; cin >> i >> c;
      for(int j = 1; j <= 9; j++) {
        if(i % j == 0 || hasNum(i, j))
          dp[j].update(i, c - a[i]); 
      }
      pre.update(i, c - a[i]);
      a[i] = c;
    }
    else if(type == 2) {
      int l, r, k; cin >> l >> r >> k;
      cout << pre.get(l, r) + dp[k].get(l, r) << '\n';
    }
  }  
}

