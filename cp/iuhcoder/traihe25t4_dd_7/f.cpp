#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define CLOVE2004 signed main()
#define ll long long
#define int long long
// typedef tree <pair<ll,ll>, null_type , less<pair<ll,ll>>, rb_tree_tag , tree_order_statistics_node_update > oderset;
const ll maxn = 3e5 + 2;
const ll LIM = 1e6 + 5;
const long long INF = 2000000000000000000LL;
const ll sn = 450;
const ll mod = 1e9 + 7;

CLOVE2004 {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k; cin >> n >> k;
  vector<int> pri(k);
  for(int i = 0; i < k; ++i) cin >> pri[i];
  int le = 0, ri = 1e18;
  int mx = (1ll << k);
  auto f = [&](int x) -> bool {
    int v = x;
    for(int i = 0; i < mx; ++i) {
      int cur = 1, sign = -1;
      for(int j = 0; j < k; ++j) {
        if(i & (1ll << j)) {
          cur *= pri[j];
          sign *= -1;
        }
      }
      v += sign*(x/cur);
    }
    return v >= n;
  };
  while(ri - le > 1) {
    int mi = (ri + le)/2;
    if(f(mi)) ri = mi;
    else le = mi;

  }
  cout << ri;

  return 0;
}
