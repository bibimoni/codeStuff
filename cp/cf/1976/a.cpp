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
    string s;
    cin >> s;
    bool ok = true;
    auto id = [&] (char x) {
      return '9' >= x && x >= '0'; 
    };
    auto ic = [&] (char x) {
      return 'a' <= x && x <= 'z';
    };
    vector<char> t1, t2;
    for(int i = 0; i < n; i++) {
      if(i < n - 1 && ic(s[i]) && id(s[i + 1])) {
        ok = false;
      }
      if(ic(s[i]))
        t1.push_back(s[i]);
      if(id(s[i]))
        t2.push_back(s[i]);
    }
    cout << (ok && is_sorted(t1.begin(), t1.end()) && is_sorted(t2.begin(), t2.end()) ? "YES\n" : "NO\n");
  }
}


