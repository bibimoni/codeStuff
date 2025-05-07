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
  string t = "122333";
  string s;
  cin >> s;
  bool ok = false;
  do {
    if (s == t) {
      ok = true;
    }
  } while (next_permutation(t.begin(), t.end()));
  cout << (ok ? "Yes\n" : "No\n");
}


