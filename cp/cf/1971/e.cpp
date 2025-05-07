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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k);
    for(int i = 0; i < k; i++)
      cin >> a[i];
    vector<int> b(k);
    for(int i = 0; i < k; i++)
      cin >> b[i];
    while(q--) {
      int d;
      cin >> d;
      int l = 0, r = k - 1, ret = -1;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] > d) {
          r = mid - 1;
        }
        else {
          l = mid + 1;
          ret = mid;
        }
      }
      if(a[ret] == d) {
        cout << b[ret] << ' ';
        continue;
      }
      if(ret == -1) {
        // dbg(v);
        int ans = d * b[0] / a[0];
        cout << ans << ' ';
        continue;
      }
      int ans = b[ret] + (d - a[ret]) * ((ret == k - 1 ? n : b[ret + 1]) - b[ret]) / ((ret == k - 1 ? n : a[ret + 1]) - a[ret]);
      cout << ans << ' ';
    }
    cout << '\n';
  }
}


