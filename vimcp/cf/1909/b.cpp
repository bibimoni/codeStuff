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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 2; i <= INF; i *= 2) {
      map<int, int> cnt;
      for(int j = 0; j < n; j++) {
        cnt[a[j] % i]++;
      }
      if(cnt.size() == 2) {
        cout << i << '\n';
        break;
      }
    }
  }
}

