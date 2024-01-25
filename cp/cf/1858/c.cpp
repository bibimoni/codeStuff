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
    int n; cin >> n;
    vector<int> minPrime(n + 1, 0);
    minPrime[1] = 1;
    for(int i = 2; i * i <= n; i++)
      if(!minPrime[i]) {
        minPrime[i] = i;
        for(int j = i * i; j <= n; j += i)
          if(!minPrime[j]) minPrime[j] = i;
      }
    for(int i = 2; i <= n; i++) if(!minPrime[i]) minPrime[i] = i;
    vector<bool> mark(n + 1, false);
    vector<int> ans(n);
    int id = 0;
    for(int i = n; i >= 1; i--) {
      if(mark[i]) continue;
      mark[i] = true;
      ans[id++] = i;
      int j = i;
      while(!mark[j / minPrime[j]]) {
        ans[id++] = j / minPrime[j];
        mark[j / minPrime[j]] = true;
        j /= minPrime[j];
      }
    }
    for(int i : ans) cout << i << ' ';
      cout << '\n';
  }
}


