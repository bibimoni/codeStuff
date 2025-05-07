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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int q, k;
  cin >> q >> k;
  ordered_set<int> os;
  set<int> st;
  auto add = [&] (int x, int y) {
    if(y - x > k) {
      st.insert(y);
    } 
  };
  auto remove = [&] (int x, int y) {
    if(y - x > k) {
      st.erase(y);
    }
  };
  os.insert(-INF);
  os.insert(INF);
  st.insert(INF);
  while(q--) {
    int t, x;
    cin >> t >> x;
    if(t == 1) {
      auto it = os.find(x);
      if(it == os.end()) {
        it = os.lower_bound(x);
        remove(*prev(it), *it);
        add(*prev(it), x);
        add(x, *it);
        os.insert(x);
      } else {
        remove(*prev(it), *it);
        remove(*it, *next(it));
        add(*prev(it), *next(it));
        os.erase(it);
      }
    } else {
      auto it = st.upper_bound(x);
      cout << os.order_of_key(*it) - os.order_of_key(*prev(it)) << '\n';
    }
  }
}

