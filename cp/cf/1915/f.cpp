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
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <class T, class U = null_type, class cmp = less<T>>
using ordered_set = tree<T, U, cmp, rb_tree_tag,tree_order_statistics_node_update>;
 
#define int long long
const int N = (int) 2e5;
 
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1];
    }
    ordered_set<array<int, 2>> s;
    sort(a.begin(), a.end(), [&] (array<int, 2> m, array<int, 2> n) {
      return m[1] < n[1];
    });
    int ans = 0;
    for(int i = 0; i < n; i++) {
      ans += i - s.order_of_key({a[i][0], i});
      s.insert({a[i][0], i});
    }
    cout << ans << '\n';
  }
}