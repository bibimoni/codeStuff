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

struct MergeSortTree {
  vector<pair<vector<int>, vector<int>>> st;
  int n;
  MergeSortTree(int _n) : n(_n) {
    st.assign(4 * n + 5, pair<vector<int>, vector<int>>{vector<int>{}, vector<int>{}});
  }

  void merge_sort(vector<int> &dst, vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
      if (a[i] < b[j]) {
        dst.push_back(a[i]);
        i += 1;
      } else {
        dst.push_back(b[j]);
        j += 1;
      }
    }
    while (i < (int)a.size()) {
      dst.push_back(a[i]);
      i += 1;
    }
    while (j < (int)b.size()) {
      dst.push_back(b[j]);
      j += 1;
    }
  }

  void build(const vector<int> &a) {
    build(a, 1, 1, n);
  }

  void build(const vector<int> &a, int id, int l, int r) {
    if (l == r && (int)a.size() > l) {
      st[id].first.push_back(a[l]);
      st[id].second.push_back(a[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    merge_sort(st[id].first, st[id * 2].first, st[id * 2 | 1].first);
    int cur = 0;
    for (int i : st[id].first) {
      cur += i;
      st[id].second.push_back(cur);
    }
  }

  pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    return pair<int, int>{a.first + b.first, a.second + b.second};
  }

  pair<int, int> query(int u, int v, int x) {
    return query(u, v, x, 1, 1, n);
  }

  pair<int, int> query(int u, int v, int x, int id, int l, int r) {
    if (v < l || r < u) {
      return pair<int, int>{0, 0};
    }
    if (u <= l && r <= v) {
      int lo = 0, hi = (int)st[id].first.size() - 1, ret = -1;
      while (lo <= hi) {
        int mid = (lo + hi) >>  1;
        if (st[id].second[mid] <= x) {
          ret = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      return {ret == -1 ? 0 : st[id].second[ret], ret + 1};
    }
    int mid = (l + r) >> 1;
    return combine(query(u, v, x, id * 2, l, mid), query(u, v, x, id * 2 | 1, mid + 1, r));
  }
};

struct Query {
  int l, r, x;
  Query() {}
  Query(int _l, int _r, int _x) 
    : l(_l), r(_r), x(_x) {}
};

struct SegTree {
  array<vector<int>, 2> st, best;
  vector<Query> que;
  int n;
  SegTree(int _n, const vector<Query> &_que) : n(_n), que(_que) {
    for (int k : {0, 1}) {
      st[k].assign(4 * n + 5, -1); 
      best[k].assign(n + 5, -1);
    }
  }

  void update_st(int id, int index) {
    if (index == -1) {
      return;
    }
    if (st[0][id] == -1 || que[st[0][id]].x < que[index].x) {
      st[1][id] = st[0][id];
      st[0][id] = index;
    } else if (st[1][id] == -1 || que[st[1][id]].x < que[index].x) {
      st[1][id] = index;
    }
  }

  void update(int u, int v, int index) {
    update(u, v, index, 1, 1, n);
  }

  void update(int u, int v, int index, int id, int l, int r) {
    if (v < l || r < u) {
      return;
    }
    if (u <= l && r <= v) {
      update_st(id, index);
      return;
    }
    int mid = (l + r) >> 1;
    update(u, v, index, id * 2, l, mid);
    update(u, v, index, id * 2 | 1, mid + 1, r);
  }

  void build() {
    build(1, 1, n);
  }

  void build(int id, int l, int r) {
    if (l == r) {
      for (int k : {0, 1}) {
        best[k][l] = st[k][id];
      }
      return;
    }
    for (int k : {0, 1}) {
      update_st(id * 2, st[k][id]);
      update_st(id * 2 | 1, st[k][id]);
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 | 1, mid + 1, r);
  }
};



signed main() { 
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  MergeSortTree mst(n);
  mst.build(a);

  vector<Query> que(q);
  for (int i = 0; i < q; i++) {
    cin >> que[i].l >> que[i].r >> que[i].x; 
  }
  
  SegTree st(n, que);
  for (int i = 0; i < q; i++) {
    Query query = que[i];
    st.update(query.l, query.r, i);
  }
  st.build();
  int tot = accumulate(a.begin() + 1, a.end(), int(0));
  vector<pair<int, int>> ans(q);
  for (int i = 0; i < q; i++) {
    Query query = que[i];
    auto [sum, cnt] = mst.query(query.l, query.r, query.x);
    ans[i].first = tot - sum + cnt * query.x;
  }
  
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i];
    if (st.best[0][i] != -1 && que[st.best[0][i]].x > a[i]) {
      cur -= a[i];
      cur += que[st.best[0][i]].x;
    }
    if (st.best[0][i] != -1) {
      ans[st.best[0][i]].second -= max(a[i], que[st.best[0][i]].x);
      if (st.best[1][i] == -1) {
        ans[st.best[0][i]].second += a[i];
      } else {
        ans[st.best[0][i]].second += max(a[i], que[st.best[1][i]].x);
      }
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i].first << ' ' << ans[i].second + cur << '\n';
  }
}


