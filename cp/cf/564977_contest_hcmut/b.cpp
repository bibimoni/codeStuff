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

// segtree with one-based indexing
//
// build:
//    SegTree<int> seg(n); // vector<int> a(n + 1)
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(pos, inc); //increase a[pos] to a[pos] + inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template<class T>
struct SegTree {
  vector<T> st;
  int n;
  function<T(T, T)> cmp;
  int LB;
  SegTree() {}
  SegTree(int _n, function<T(T, T)> _cmp, int _LB) : n(_n), cmp(_cmp), LB(_LB) {
    T default_value = 0;
    st.assign(4 * n + 5, default_value);
  }
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T>& a, int id, int l, int r) {
    if(l == r) {
      st[id] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = cmp(st[id * 2], st[id * 2 | 1]);
  }
  void update(int pos, T inc) {
    update(pos, inc, 1, 1, n);
  }
  void update(int pos, T inc, int id, int l, int r) {
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
    st[id] = cmp(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return ;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return cmp(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int q;
  cin >> q;
  vector<array<int, 3>> que(q);

  vector<int> s;
  for (int i = 0; i < q; i++) {
    cin >> que[i][0] >> que[i][1] >> que[i][2];
    s.push_back(que[i][1]);
    s.push_back(que[i][2]);
  }

  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  
  auto idx = [&] (int val) -> int {
    return lower_bound(s.begin(), s.end(), val) - s.begin() + 1;
  };

  int tot = s.size();

  const int INF = 1e18;
  vector<pair<SegTree<int>, SegTree<int>>> st(2);
  for (auto &[stM, stm] : st) {
    stM = SegTree<int>(tot + 5, [&] (int a, int b) {
      return min(a, b);
    }, INF);
    stm = SegTree<int>(tot + 5, [&] (int a, int b) {
      return max(a, b);
    }, -INF);
  }

  multiset<int> st1, st2;

  for (auto p : que) {
    int t = p[1];
    if (t == 3) {
      int x1 = p[1], x2 = p[2];
    } else {
      int x = p[1], y = p[2];
      int id = idx(x);
      if (t == 1) {
        auto &[stM_1, stm_1] = st[0];
        auto &[stM_2, stm_2] = st[1];
        st1.insert(x + y);
        int valM = *prev(st1.end());
        stM_1.update(id, x + y);
        int valm = *st1.begin();
        stm_1.update(id, valm);

        st2.insert(x - y);
        valM = *prev(st2.end());
        stM_2.update(id, valM);
        valm = *st2.begin();
        stm_2.update(id, valm);
      } else if (t == 2) {

      }
    }
  }

}


