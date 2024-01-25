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
const int INF = 222;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x; cin >> x;
    if(x == 2) {
      cout << "1\n0\n";
      continue;
    }
    vector<int> len;
    x--;
    int tmp = x;
    while(tmp > 0) {
      int l = log2(tmp + 1ll);
      len.push_back(l);
      tmp -= pow(2ll, l);
    }
    int totalSub = 0;
    vector<int> ans;
    int prev = INF;
    for(int l : len) {
      for(int i = prev - l + 1; i <= prev; i++) {
        ans.push_back(i);
      }
      totalSub += pow(2ll, l) - 1ll;
      dbg(pow(2ll, l));
      prev -= l;
    }
    dbg(totalSub);
    for(int i = totalSub + 1; i <= x; i++) {
      ans.push_back(-INF);
    }
    dbg(len);
    if(ans.size() > 200 || totalSub > x) {
      cout << "-1\n";
    }
    else {
      cout << ans.size() << '\n';
      for(int i : ans) cout << i << ' ';
      cout << '\n';
    }
  }
}


