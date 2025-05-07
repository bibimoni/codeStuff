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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int m;
    cin >> m;
    while (m--) {
      string s;
      cin >> s;
      if (int(s.size()) != n) {
        cout << "NO\n";
        continue;
      }
      map<int, set<char>> idx;
      for (int j = 0; j < int(s.size()); j++) {
        idx[a[j]].insert(s[j]);
      } 
      set<char> other;
      bool ok = true;
      for (auto [_, st] : idx) {
        ok &= int(st.size()) == 1;
        ok &= other.find(*st.begin()) == other.end();
        other.insert(*st.begin());
      }
      cout << (ok ? "YES\n" : "NO\n");
    }
  }
}



