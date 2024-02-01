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
  vector<int> coPrime[1001];
  for(int i = 1; i <= 1000; i++) {
    for(int j = 1; j <= 1000; j++) {
      if(__gcd(i, j) == 1) {
        coPrime[j].push_back(i);
      }
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    int ans = -1;
    int mark[1001];
    memset(mark, -1, sizeof mark);
    for(int &i : a) {
      cin >> i;
    }
    mark[a[0]] = 0; 
    for(int i = 1; i < n; i++) {
      mark[a[i]] = i;
      for(int co : coPrime[a[i]]) {
        if(mark[co] != -1) {
          ans = max(ans, mark[co] + i + 2);
        }
      }
    }
    cout << ans << '\n';
  }
}

