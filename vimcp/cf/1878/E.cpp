/**
 * File              : E.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 29.09.2023
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

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  MULTI {
    int n; cin >> n;
    vector<vector<int>> pre(n, vector<int>(32, 0));
    int a[n]; 
    for(int i = 0; i < n; i++) {
      cin >> a[i]; int j = 0;
      while(a[i] && i == 0) 
        pre[0][j++] = (a[i] & 1), a[i] >>= 1;
    }
    for(int i = 1; i < n; i++) {
      int j = 0;
      while(a[i])
        pre[i][j] = (a[i] & 1) + pre[i - 1][j], j++, a[i] >>= 1; 
    }
    MULTI {
      int l, k; cin >> l >> k;
      int r = n - 1, ans = -2;
      l--; int tmp = l;
      while(l <= r) {
        int mid = (l + r) >> 1;
        int num = 0;
        for(int i = 0; i < 32; i++) {
          if((pre[mid][i] - ((tmp - 1 >= 0) ? pre[tmp - 1][i] : 0)) == mid - tmp + 1) {
            num += pow(2ll, i);
          }
        }
        if(num >= k) {
          l = mid + 1;
          ans = mid;
        }
        else {
          r = mid - 1;
        }
      }
      cout << ans + 1 << ' ';
    }
    cout << endl;
  }
}
