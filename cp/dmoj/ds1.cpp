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
#define all(x)         x.begin(), x.end()
const int N = (int) 1e5 + 5;
int ft[N], cnt[N];
int getCnt(int id) {
  int ans = 0;
  while(id > 0) {
    ans += cnt[id];
    id -= (id & -id);
  }
  return ans;
}
int get(int id) {
  int ans = 0;
  while(id > 0) {
    ans += ft[id];
    id -= (id & -id);
  }
  return ans;
}
void updateCnt(int id, int val) {
  while(id < N) {
    cnt[id] += val;
    id += (id & -id);
  }
}
void update(int id, int val) {
  while(id < N) {
    ft[id] += val;
    id += (id & -id);
  }
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  int a[n + 1]; 
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, a[i]);
    updateCnt(a[i], 1);
  }
  while(m--) {
    char type; cin >> type;
    if(type == 'C') {
      int x, m; cin >> x >> m;
      update(x, m - a[x]);
      updateCnt(a[x], -1);
      a[x] = m;
      updateCnt(a[x], 1);
    }
    if(type == 'S') {
      int l, r; cin >> l >> r;
      cout << (get(r) - get(l - 1)) << '\n';
    }
    if(type == 'Q') {
      int m; cin >> m;
      cout << getCnt(m) << '\n';
    }
  }
}

