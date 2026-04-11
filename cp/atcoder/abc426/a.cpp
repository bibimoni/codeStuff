/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
  map<string, int> mp;
  mp["Ocelot"] = 1;
  mp["Serval"] = 2;
  mp["Lynx"] = 3;
  string s, t;
  cin >> s >> t;
  cout << (mp[s] >= mp[t] ? "Yes\n" : "No\n");
}
