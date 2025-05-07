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
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  int cnt = count(s.begin(), s.end(), '@');
  cout << n - (cnt - min(d, cnt)) << '\n';
}


