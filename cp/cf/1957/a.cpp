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
    int ans = 0;
    map<int, int> f;
    for(int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	f[x]++;
    }
    for(auto [k, v] : f) {
    	ans += v / 3;
    }
    cout << ans << '\n';
  }
}


