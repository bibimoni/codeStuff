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

bool isLower(char i) {
  return tolower(i) == i;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    string t = "";
    vector<bool> up(n, false);
    bool ok = false;
    for(int i = 0; i < n; i++) {
      if(a[i] == b[i] && a[i] != c[i] && b[i] != c[i]) ok = true;
      if(a[i] != b[i] && a[i] != c[i] && b[i] != c[i]) ok = true;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


