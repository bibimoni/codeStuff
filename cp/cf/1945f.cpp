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
#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

/*** Needs C++11 or C++14 ***/

/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in long long

struct Treap { /// hash = 96814
  int len;
  const int ADD = 1000010;
  const int MAXVAL = 1000000010;
  tr1::unordered_map <long long, int> mp; /// Change to int if only int in treap
  tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

  Treap() {
    len = 0;
    T.clear(), mp.clear();
  }

  inline void clear(){
    len = 0;
    T.clear(), mp.clear();
  }

  inline void insert(long long x){
    len++, x += MAXVAL;
    int c = mp[x]++;
    T.insert((x * ADD) + c);
  }

  inline void erase(long long x){
    x += MAXVAL;
    int c = mp[x];
    if (c){
      c--, mp[x]--, len--;
      T.erase((x * ADD) + c);
    }
  }

  /// 1-based index, returns the K'th element in the treap, -1 if none exists
  inline long long kth(int k){
    if (k < 1 || k > len) return -1;
    auto it = T.find_by_order(--k);
    return ((*it) / ADD) - MAXVAL;
  }

  /// Count of value < x in treap
  inline int count(long long x){
    x += MAXVAL;
    int c = mp[--x];
    return (T.order_of_key((x * ADD) + c));
  }

  /// Number of elements in treap
  inline int size(){
    return len;
  }
};
#define int long long

const int N = 2e5 + 5, INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    Treap treap;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> v[i];
      treap.insert(v[i]);
    }
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    int ans = treap.kth(n), cnt = 1;
    for(int i = 2; i <= n; i++) {
      treap.erase(v[p[i - 1]]);
      treap.insert(0);
      int qry = treap.kth(n - i + 1);
      if(!qry)
        break;
      if(ans < i * qry) {
        ans = i * qry;
        cnt = i;
      }
    }
    cout << ans << ' ' << cnt << '\n';
  }
}

