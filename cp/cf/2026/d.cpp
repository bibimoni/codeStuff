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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> pre(n + 2, 0);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  pre[n + 1] = pre[n];
  auto s = [&] (int l, int r) -> int {
    return pre[r] - pre[l - 1];
  };
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + s(1, i);
  }
  vector<int> coa(n + 1);
  for (int i = 2; i <= n; i++) {
    coa[i] = coa[i - 1] + (n - (i - 1) + 1) * a[i - 1];
  }
  vector<int> rs(n + 2);
  for (int i = 1; i <= n; i++) {
    rs[i] = rs[i - 1] + s(i, n);
  }
  rs[n + 1] = rs[n];
  vector<int> block_sz(n + 1), block_val(n + 1), block_p(n + 1);
  for (int i = 1, sz = n; i <= n; i++, sz -= 1) {
    block_sz[i] = block_sz[i - 1] + sz;
    block_val[i] = p[n] - coa[i];
    block_p[i] = block_p[i - 1] + block_val[i];
  }
  auto find_block = [&] (int pos) -> int {
    int lo = 1, hi = n, ret = n;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (block_sz[mid - 1] < pos) {
        lo = mid + 1;
        ret = mid;
      } else {
        hi = mid - 1;
      }
    }
    return ret;
  };

  auto calc = [&] (int pos) -> int {
    if (pos == 0) {
      return 0;
    }
    int block_id = find_block(pos);
    pos -= block_sz[block_id - 1];
    pos += block_id - 1;
    int cur = block_p[block_id - 1];
    cur += s(block_id, n + 1) * (pos - block_id + 1) - rs[pos + 1] + rs[block_id];
    return cur;
  };

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << '\n';
  }
}


