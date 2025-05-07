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
#define all(x)         x.begin(), x.end()
const int N = (int) 1e5 + 5, MAXN = (int) 8e4 + 5, L = 31;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  vector<vector<int>> divs(N);
  for(int i = N - 1; i >= 1; i--  ) {
    for(int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
  while(tt--) {
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    vector<int> cnt(N, 0), tmp(N, 0);
    for(int i = 1; i <= n; i++) {
      for(int j : divs[a[i]]) {
        tmp[j] += cnt[j];
        for(int k : divs[j]) {
          if(j == k) continue;
          tmp[k] -= tmp[j];
        }
        ans += j * tmp[j] * (n - i);
      }
      for(int j : divs[a[i]]) cnt[j]++, tmp[j] = 0;
    }
    //dbg(divs);
    cout << ans << '\n';
  }
}


