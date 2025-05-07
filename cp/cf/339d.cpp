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

const int N = (int) (1 << 17);
vector<int> pwr(N);
// segtree with one-based indexing
//
// build:
//    segtree<int, N> seg; // N is constant
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(pos, inc); //increase a[pos] to a[pos] + inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template<class T, int SZ>
struct segTree {
  vector<T> st;
  segTree() {
    T default_value = 0;
    st.assign(4 * SZ, default_value);
  }
  void build(const vector<T>& a, int id = 1, int l = 1, int r = SZ) {
    if(l == r) {
      if(l < a.size()) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    if(pwr[r - l + 1] % 2 == 0)
      st[id] = st[id * 2] ^ st[id * 2 | 1];
    else 
      st[id] = st[id * 2] | st[id * 2 | 1];
  }
  void update(int pos, T inc, int id = 1, int l = 1, int r = SZ) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id] = inc;
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    if(pwr[r - l + 1] % 2 == 0)
      st[id] = st[id * 2] ^ st[id * 2 | 1];
    else 
      st[id] = st[id * 2] | st[id * 2 | 1];
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) {
      return 0;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    if(pwr[r - l + 1] % 2 == 0)
      return query(u, v, id * 2, l, mid) ^ query(u, v, id * 2 | 1, mid + 1, r);
    else 
      return query(u, v, id * 2, l, mid) | query(u, v, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 0; i <= 17; i++) {
    pwr[(1 << i)] = i;
  }
  vector<int> a((1 << n) + 1);
  segTree<int, N> seg;
  for(int i = 1; i <= (1 << n); i++) {
    cin >> a[i];
  }
  seg.build(a);
  while(q--) {
    int b, p;
    cin >> p >> b;
    seg.update(p, b);
    cout << seg.st[1] << '\n';
  }
}

