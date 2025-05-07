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
  int tt;
  cin >> tt;
  while (tt--) {
    string n;
    cin >> n;
    if (n.size() <= 2) {
      cout << "NO\n";
      continue;
    }
    int f = stoi(n.substr(0, 2));
    int s = stoi(n.substr(2));
    cout << (f == 10 && s >= 2 && to_string(s) == n.substr(2) ? "YES\n" : "NO\n");
  }
}


