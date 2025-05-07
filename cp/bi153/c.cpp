// segtree with one-based indexing
// supports range update
//
// build:
// SegTree<T, F, U> seg(<cap>, <default>, <trash>)
// SegTree<int, 
//    [&] (int v_1, int v_2) { return min(v_1, v_2); },
//    [&] (int v_1, int v_2) { return v_1 + v_2; }>
//  st_mn(n, 0, int(1e9));
//
//  vector<int> a(n + 1);
//  seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(l, r, inc); // apply a[l -> r] = U(a[l -> r], inc)
//
// query:
//    seg.query(l, r)

#if __cplusplus >= 201703L

template <class T, auto F, auto U> struct SegTree {
  static_assert(is_convertible_v<decltype(F), function<T(T, T)>>, "F must be T(T, T)");
  static_assert(is_convertible_v<decltype(U), function<T(T, T)>>, "U must be T(T, T)");

#else 

template <class T, T (*F)(T, T), T (*U)(T, T)> struct SegTree {

#endif 

  vector<T> st, lazy;
  int n;
  T trash_val;
  T default_value;
  SegTree() : SegTree(0) {}
  explicit SegTree(int _n, T _default_value, T _trash_val) 
  : n(_n), trash_val(_trash_val), default_value(_default_value) {
    st.assign(4 * n + 5, default_value);
    lazy.assign(4 * n + 5, default_value);
  }  

  // one-indexed
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T> &a, int id, int l, int r) {
    lazy[id] = default_value;
    if(l == r) {
      if(l < (int)a.size()) {
        st[id] = a[l];
