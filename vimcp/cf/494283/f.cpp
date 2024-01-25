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
const int N = (int) 1e5 + 5;
set<int> st[4 * N]; int a[N];
set<int> merge(set<int> a, set<int> b) {
  set<int> c;
  c.insert(a.begin(), a.end());
  c.insert(b.begin(), b.end());
  return c;
}

void build(int id, int l, int r) {
  if(l == r) {
    st[id].insert(a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(id * 2, l, mid);
  build(id * 2 | 1, mid + 1, r);
  st[id] = merge(st[id * 2], st[id * 2 | 1]);
}

set<int> get(int id, int l, int r, int u, int v) {
  if(v < l || r < u) return {};
  if(u <= l && r <= v) {
    // dbg(u, v, l, r, st[id], id);
    return st[id];
  }
  int mid = (l + r) >> 1;
  return merge(get(id * 2, l, mid, u, v), get(id * 2 | 1, mid + 1, r, u, v));
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  int q; cin >> q;
  while(q--) {
    int l, r; cin >> l >> r;
    cout << get(1, 1, n, l, r).size() << '\n';
  }
}

