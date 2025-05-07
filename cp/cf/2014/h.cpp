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

int block_size;

struct Query {
  int l, r, id;

  Query() {}
  Query(int l, int r, int id) {
    this->l = l;
    this->r = r;
    this->id = id;
  }
  inline pair<int, int> to_pair() const {
    return {l / block_size, ((l / block_size) & 1 ? -r : r)};
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    block_size = int(sqrt(n));
    vector<int> a(n + 1);
    vector<int> s;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s.push_back(a[i]);
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      queries[i] = Query(l, r, i);
    }
    
    sort(s.begin(), s.end());
    for (int i = 1; i <= n; i++) {
      a[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin() + 1;
    }

    sort(queries.begin(), queries.end(), [&] (const Query &a, const Query &b) {
      return a.to_pair() < b.to_pair();
    });

    int cur = 0;
    vector<int> cnt(n + 1, 0);
    auto add = [&] (int id) -> void {
      cnt[a[id]] += 1;
      if (cnt[a[id]] % 2 == 0) {
        cur -= 1;
      } else {
        cur += 1;
      }
    };
    auto rem = [&] (int id) -> void {
      cnt[a[id]] -= 1;
      if (cnt[a[id]] % 2 == 0) {
        cur -= 1;
      } else {
        cur += 1;
      }
    };
    int cur_l = 1, cur_r = 0;
    vector<int> ans(q);
    for (Query &q : queries) {
      while (cur_l > q.l) {
        cur_l -= 1;
        add(cur_l);
      }
      while (cur_r < q.r) {
        cur_r += 1;
        add(cur_r);
      }
      while (cur_l < q.l) {
        rem(cur_l);
        cur_l += 1;
      }
      while (cur_r > q.r) {
        rem(cur_r);
        cur_r -= 1;
      }
      ans[q.id] = cur == 0;
    }
    for (int i = 0; i < q; i++) {
      cout << (ans[i] ? "YES\n" : "NO\n");
    }
  }
}

