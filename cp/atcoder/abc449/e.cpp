/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
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

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  vector<pair<int, int>> cnt(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]].first += 1;
  }
  for (int i = 1; i <= m; i++) {
    cnt[i].second = i;
  }
  sort(cnt.begin(), cnt.end());
  dbg(cnt);

  int q;
  cin >> q;
  vector<int> que(q);
  for (int i = 0; i < q; i++) {
    cin >> que[i]; 
  }

  vector<int> p(q);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return que[i] < que[j];
  });

  vector<int> ans(q);
  ordered_set<int> cur;
  int pt = 0, sz = n;
  for (int id = 0; id < q; id++) {
    int x = que[p[id]];
    dbg("new-----",x);
    if (x <= n) {
      ans[p[id]] = a[x]; 
      continue;
    } 

    auto upd = [&]() {
      while (pt < m && (cnt[pt].first == cnt[pt + 1].first)) {
        cur.insert(cnt[pt].second);
        pt += 1;
      }
      if (pt <= m)
        cur.insert(cnt[pt].second); 
      sz += pt * (pt == m ? 0 : (cnt[pt + 1].first - cnt[pt].first));
    };

    dbg("before", pt, sz);
    while (pt < m && sz < x) {
      pt += 1;
      upd();
    }
    dbg("after", pt, sz);
    
    if (pt == m) {
      int ret = (x - sz - 1) % m + 1;
      dbg("last", ret, x, sz);
      ans[p[id]] = ret;
      continue;
    } 


    int block = (cnt[pt + 1].first - cnt[pt].first) * pt;
    int del = sz - block;
    int nx = (x - del - 1) % pt;
    int ret = *cur.find_by_order(nx);
    dbg(del, nx, ret);
    ans[p[id]] = ret;
  }
  dbg(ans);

  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}
