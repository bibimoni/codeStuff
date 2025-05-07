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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> d[i];
    }
    if(accumulate(d.begin() + 1, d.end(), 0ll) & 1) {
      cout << "NO\n";
      continue;
    }
    //Erdős–Gallai theorem
    //sum(1, i) d_k <= k * (k - 1) + sum(i + 1, n) min(d_i, k)
    sort(d.begin() + 1, d.end(), greater<int>());
    for(int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + d[i];
    }
    bool ok = true;
    for(int i = 1; i <= n; i++) {
      int l = i + 1, r = n, ret = -1;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(d[mid] > i) {
          l = mid + 1;
        }
        else {
          r = mid - 1;
          ret = mid;
        }
      }
      int left = (ret != -1 ? ((ret - i - 1) * i + pre[n] - pre[ret - 1]) : i * (n - i));
      if(pre[i] > i * (i - 1) + left) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}

