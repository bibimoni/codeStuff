/**
 * Author: distiled
 */

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC optimize("O3")

#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
const int MOD = 1234567891ll, N = (int) 1e5 + 5;
set<int> st[4 * N]; int a[N];

set<int> merge(set<int> a, set<int> b) {
  set<int> c;
  c.insert(a.begin(), a.end());
  c.insert(b.begin(), b.end());
  return c;
}

void build(int id, int l, int r) {
  if(l == r) {
    st[id].insert(a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(id * 2, l, mid);
  build(id * 2 | 1, mid + 1, r);
  st[id] = merge(st[id * 2], st[id * 2 | 1]);
}

set<int> get(int id, int l, int r, int u, int v) {
  if(v < l || r < u) return {};
  if(u <= l && r <= v) {
    // dbg(u, v, l, r, st[id], id);
    return st[id];
  }
  int mid = (l + r) >> 1;
  return merge(get(id * 2, l, mid, u, v), get(id * 2 | 1, mid + 1, r, u, v));
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, l, r; cin >> n >> l >> r;
  for(int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  vector<int> dp(n + 1, 0), pref(n + 1, 0);
  map<int, bool> mark;
  dp[0] = 1;
  vector<pair<int, int>> range(n + 1);
  for(int i = 1; i <= n; i++) {
    if(get(1, 1, n, 1, i).size() < l) {
      range[i] = {-1, -1};
      continue;
    }
    int lt = 1, rt = i;
    int posl = n, posr = 1;
    while(lt <= rt) {
      int mid = (lt + rt) >> 1;
      int cnt = get(1, 1, n, mid, i).size();
      if(l > cnt) {
        rt = mid - 1;
      }
      else  {
        lt = mid + 1;
        posr = max(posr, mid);
      }
    }
    lt = 1, rt = i;
    while(lt <= rt) {
      int mid = (lt + rt) >> 1;
      int cnt = get(1, 1, n, mid, i).size();
      if(cnt > r) {
        lt = mid + 1;
      }
      else {
        rt = mid - 1;
        posl = min(posl, mid);
      }
    }
    range[i] = {posl, posr};
  }
  pref[0] = 1;
  for(int i = 1; i <= n; i++) {
    dbg(range[i]);
    if(range[i] == (pair<int, int>) {-1, -1}) {
      pref[i] = pref[i - 1];
      continue;
    }
    auto [bl, br] = range[i];
    (dp[i] += pref[br - 1] - (bl - 2 >= 0 ? pref[bl - 2] : 0) + MOD) %= MOD;
    (pref[i] = pref[i - 1] + dp[i]) %= MOD;
  }

  cout << dp[n];
}
