/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/**
 * Description: Policy-based data structures that supports normal set operation
 * and
 *    * find_by_order(k)  returns iterator to kth element starting from 0;
 *    * order_of_key(k)   returns count of elements strictly [smaller] than k;
 * Caution:
 *    * do not define int long long before below declaration
 */

template <class T, class cmp = std::less<T>>
using ordered_set =
    tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map =
    tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), cnt(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }

  sort(a.begin() + 1, a.end(), [&](int x, int y) {
    return pair<int, int>{cnt[x], x} < pair<int, int>{cnt[y], y};
  });

  int q;
  cin >> q;
  vector<int> que(q);
  for (int i = 0; i < q; i++) {
    cin >> que[i];
  }
  vector<int> p(q);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) { return que[i] < que[j]; });

  vector<int> ans(q);
  int k = 1;
  int64_t prev = 1;
  const int inf = 1e9;
  ordered_set<int> os;
  for (int i = 0; i < q; i++) {
    int x = que[p[i]];
  }
}
