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

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

const int INF = 0, N = (int) 1e5 + 5;
int n, a[N], it[4 * N];

void update(int node, int l, int r, int i, int val) {
  if(i < l || r < i) {
    return;
  }
  if(l == r) {
    it[node] = val;
    return;
  }
  int mid = (l + r) >> 1;
  update(node * 2, l, mid, i, val);
  update(node * 2 | 1, mid + 1, r, i, val);
  it[node] = max(it[node * 2], it[node * 2 | 1]);
}
int get(int node, int l, int r, int u, int v) {
  if(v < l || r < u) {
    return -INF;
  }
  if(u <= l && r <= v) {
    return it[node];
  }
  int mid = (l + r) >> 1;
  return max(get(node * 2, l, mid, u, v), get(node * 2 | 1, mid + 1, r, u, v));
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int k; cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> dp(n + 1, 0);
  int ans = -INF;
  for(int i = 1; i <= n; i++) {
    dp[i] = a[i] + max(0ll, get(1, 1, n, max(1ll, i - k), i));
    update(1, 1, n, i, dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans;
}



