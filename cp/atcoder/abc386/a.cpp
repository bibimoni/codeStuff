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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  vector<int> p(4);
  cin >> p[0] >> p[1] >> p[2] >> p[3];
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  cout << (p.size() == 2 ? "Yes\n" : "No\n") << '\n';
}


