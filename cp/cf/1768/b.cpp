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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
      cin >> p[i];
    }
    if(is_sorted(p.begin(), p.end())) {
      cout << "0\n";
      continue;
    }
    int curr = 1, cnt = 0;
    for(int i = 0; i < n; i++) {
      if(p[i] == curr) {
        curr++;
        cnt++;
      }
    }
    dbg(curr);
    cout << ceil((n - cnt) / (double) k) << '\n';
  }
}

