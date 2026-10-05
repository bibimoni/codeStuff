/// *** needs c++11 or c++14 ***/

/// treap supporting duplicating values in set
/// maximum value of treap * add must fit in long long

struct treap { /// hash = 96814
  int len;
  const int add = 1000010;
  const int maxval = 1000000010;
  tr1::unordered_map<long long, int> mp; /// change to int if only int in treap
  tree<long long, null_type, less<long long>, rb_tree_tag,
       tree_order_statistics_node_update>
      t;

  Treap() {
    len = 0;
    T.clear(), mp.clear();
  }

  inline void clear() {
    len = 0;
    T.clear(), mp.clear();
  }

  inline void insert(long long x) {
    len++, x += MAXVAL;
    int c = mp[x]++;
    T.insert((x * ADD) + c);
  }

  inline void erase(long long x) {
    x += MAXVAL;
    int c = mp[x];
    if (c) {
      c--, mp[x]--, len--;
      T.erase((x * ADD) + c);
    }
  }

  /// 1-based index, returns the K'th element in the treap, -1 if none exists
  inline long long kth(int k) {
    if (k < 1 || k > len)
      return -1;
    auto it = T.find_by_order(--k);
    return ((*it) / ADD) - MAXVAL;
  }

  /// Count of value < x in treap
  inline int count(long long x) {
    x += MAXVAL;
    int c = mp[--x];
    return (T.order_of_key((x * ADD) + c));
  }

  /// Number of elements in treap
  inline int size() { return len; }
};
