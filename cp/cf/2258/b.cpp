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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }

    vector<int> pre(m + 1);
    for (int i = 1; i <= m; i++) {
      pre[i] = pre[i - 1] + cnt[i];
    }

    vector<int> ans(m + 1);
    int gl = 0;

    for (int i = 1; i <= m; i++) {
      int s = 0;
      vector<int> tot(25, 0);
      for (int j = 1; j <= m / i; j++) {
        int l = i * j;
        int r = min(m, (j + 1) * i - 1);

        int non = pre[r] - pre[l - 1];
        if (non == 0) {
          continue;
        }

        s += non * j;
        for (int k = 1; k <= 24ll; k++) {
          int mx = (1 << k);
          tot[k] += non * min(j, mx - 1);
          if (j == mx) {
            tot[k] += cnt[i * mx];
          }
         }

        for (int k = 1; k <= min(m, 24ll); k++) {
          ans[k] = max(ans[k], tot[k]);
        }
        gl = max(gl, s);
      }       
      
    } 

    for (int i = 24ll; i <= m; i++) {
      ans[i] = max(ans[i], gl);
    }
    
    cout << ans[1] << '\n';
    
    // for (int i = 1; i <= m; i++) {
    //   ans[i] = max(ans[i], ans[i - 1]);
    //   cout << ans[i] << " \n"[i == m];
    // }
  }
}
