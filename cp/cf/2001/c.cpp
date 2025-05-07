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
    int n;
    cin >> n;
    auto ask = [&] (int a, int b) -> int {
      cout << "? " << a << ' ' << b << '\n';
      cout.flush();
      int ret;
      cin >> ret;
      return ret;
    };
    set<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
      int dummy = ask(i, n);
      if (dummy == i) {
        edges.insert({i, n});
      } else {
        int last = dummy;
        while (dummy != i) {
          last = dummy;
          dummy = ask(i, dummy);
        }
        edges.insert({min(i, last), max(i, last)});
      }
    }
    cout << "! ";
    for (auto [a, b] : edges) {
      cout << a << ' ' << b << ' ';
    }
    cout << '\n';
    cout.flush();
  }
}


