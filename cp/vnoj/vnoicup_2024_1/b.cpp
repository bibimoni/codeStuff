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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    bool ok = true;
    for(int i = 1; i <= n; i++) {
      int cnt = 2;
      int j = i + 1;
      while(j <= n && a[i] < b[i]) {
        int need = b[i] - a[i];
        if(need >= a[j] * cnt) {
          a[i] += a[j] * cnt;
          a[j++] = 0;
        }
        else {
          int k = (int) ceil(need / (double) cnt);
          a[j] -= k;
          a[i] += k * cnt;
          break; 
        }
        cnt *= 2;
      }
      if(a[i] < b[i]) {
        ok = false;
        break;
      }
      a[i] -= b[i];
      if(i < n) {
        a[i + 1] += a[i] / 2;
        a[i] = 0;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


