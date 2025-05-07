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
#define double long double

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    //1000 100 1 10 1
    //(2, 1) (i, j)
    //a_i^j <= a_j
    //j <= log_a_i(a_j)
    //1^3 <= 1
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      int l = 0, r = n - 1, ret = -1;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(i * log2(b[mid]) <= log2(a[i])) {
          l = mid + 1;
          ret = mid;
        }
        else {
          r = mid - 1;
        }
      }
      ans += ret + 1;
    }
    cout << ans << '\n';
  }
}


