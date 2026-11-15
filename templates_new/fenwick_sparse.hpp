template <class T, class U> class SparseFenwick2D {
  vector<vector<T>> a;
  vector<U> xs;
  vector<pair<U, U>> l;
  vector<vector<U>> ys;
  int n;

  void compress_x() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    n = (int)xs.size();
    ys.resize(n + 1);
    a.resize(n + 1);
  }

public:
  void init() {
    for (int i = 1; i <= n; i++) {
      sort(ys[i].begin(), ys[i].end());
      ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
      a[i].assign(ys[i].size() + 1, static_cast<U>(0));
    }
  }

  SparseFenwick2D() {}

  SparseFenwick2D(vector<pair<U, U>> &ll) : l(ll) {
    for (auto [x, _] : ll) {
      xs.push_back(x);
    }
    compress_x();
    for (auto [x, y] : ll) {
      fake_add(x, y);
    }
    init();
  }

  SparseFenwick2D(vector<U> &all_x) : xs(all_x) { compress_x(); }

  int get_x(U x) {
    return int(lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1);
  }

  void fake_add(U x, U y) {
    for (U i = get_x(x); i <= n; i += i & -i) {
      ys[i].push_back(y);
    }
  }

  void update(U r, U c, T del) {
    for (U i = get_x(r); i <= n; i += i & -i) {
      int j =
          int(lower_bound(ys[i].begin(), ys[i].end(), c) - ys[i].begin() + 1);
      for (; j < int(a[i].size()); j += j & -j) {
        a[i][j] += del;
      }
    }
  }

  T query(U r, U c) {
    T res = 0;
    for (U i = get_x(r); i > 0; i -= i & -i) {
      int j =
          int(lower_bound(ys[i].begin(), ys[i].end(), c) - ys[i].begin() + 1);
      for (; j > 0; j -= j & -j) {
        res += a[i][j];
      }
    }
    return res;
  }
};
