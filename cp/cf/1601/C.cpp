/**
 * File              : C.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 16.10.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define makeUnique(x)  sort(all(x)); x.erase(unique(all(x)), x.end());
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
const int 
      MAXN = (int) 1e6 + 5, 
      INF = (int) 1e18, 
      MOD = (int) 1e9 + 7; //998244353
inline int nxt() { int n; cin >> n; return n; }

struct bit {
  int tree[MAXN];
  void update(int id) {
    while(id > 0) {
      tree[id]++; id -= (id & -id);
    }
  }
  int get(int id) {
    int ans = 0;
    while(id < MAXN) {
      ans += tree[id];
      id += (id & -id);
    }
    return ans;
  }
} bit;

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  MULTI {
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);
  } 
}

