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
    int n;
    cin >> n;
    int p[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    vector<int> ans(n + 1, 0);
    int j = 1;
    ans[p[1]] = 1;
    int curr = p[1];
    for(int i = 2; i <= n; i++) {
      curr += p[i];
      while(curr > n) {
        curr -= p[j++];
      }
      int neg = 0;
      for(int k = j; k <= i; k++) {
        ans[curr - neg]++;
        neg += p[k];
      }
    }
    for(int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}


