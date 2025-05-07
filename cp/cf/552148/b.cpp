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

const int BLOCK = 320;

struct Query {
  int l, r, opt, x, id;
  Query(int l, int r, int opt, int x, int id) : 
    l(l), r(r), opt(opt), x(x), id(id) {}
  Query() {}
  inline pair<int, int> to_pair() const {
    return pair<int, int>{l / BLOCK, ((l / BLOCK) & 1 ? -r : r)};
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> h(n + 1);
  vector<int> cnt((int)4e5 + 5, 0);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  vector<Query> queries(q);
  for (int i = 0; i < q; i++) {
    int opt, l, r, x;
    cin >> opt >> l >> r >> x;
    queries[i] = Query(l, r, opt, x, i);
  }
  sort(queries.begin(), queries.end(), [&] (const Query &a, const Query &b) {
    return a.to_pair() < b.to_pair();
  });
  int cur_l = 1, cur_r = 0;

  vector<array<int, 3>> ans_opt((int)1e5 + 5);
  auto add = [&] (int id, int x) -> void {
    if (cnt[x + h[id]] > 0) {
      ans_opt[x][0] += 1;
    }
    if (h[id] > x && cnt[h[id] - x] > 0) {
      ans_opt[x][0] += 1;      
    }
    if (x > h[id] && cnt[x - h[id]] > 0) {
      ans_opt[x][1] += 1;
    }
    if (x % h[id] == 0 && cnt[x / h[id]] > 0) {
      ans_opt[x][2] += 1;
    }
    cnt[h[id]] += 1;
  };
  auto rem = [&] (int id, int x) -> void {
    cnt[h[id]] -= 1;
    if (cnt[x + h[id]] > 0) {
      ans_opt[x][0] -= 1;
    }
    if (h[id] > x && cnt[h[id] - x] > 0) {
      ans_opt[x][0] -= 1;      
    }
    if (x > h[id] && cnt[x - h[id]] > 0) {
      ans_opt[x][1] -= 1;
    }
    if (x % h[id] == 0 && cnt[x / h[id]] > 0) {
      ans_opt[x][2] -= 1;
    }
  };

  // a - b = x => x + b = a | b - a = x => a = b - x
  // a + b = x => x - b = a
  // a * b = x => x / b = a
  vector<int> ans(q);
  for (Query que: queries) {
    dbg(que.l, que.r, que.opt, que.x, que.id);
    while (cur_l > que.l) {
      cur_l -= 1;
      add(cur_l, que.x);
    }
    while (cur_r < que.r) {
      cur_r += 1;
      add(cur_r, que.x);
    }
    while (cur_l < que.l) {
      rem(cur_l, que.x);
      cur_l += 1;
    }
    while (cur_r > que.r) {
      rem(cur_r, que.x);
      cur_r -= 1;
    }
    dbg(cnt[1], cnt[2], cnt[3], cnt[4]);
    ans[que.id] = ans_opt[que.x][que.opt - 1] > 0;
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}


