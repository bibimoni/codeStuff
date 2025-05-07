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
    string s;
    cin >> s;

    string t = "";

    vector<int> nxt(n, n);
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] != s[i + 1]) {
        nxt[i] = i;
      } else {
        nxt[i] = nxt[i + 1];
      }
    }
    for (int i = 0; i < n; i = nxt[i] + 1) {
      t += s[i];
    }

    int cnt0 = count(t.begin(), t.end(), '0');
    int cnt1 = t.size() - cnt0;
    if (cnt0 < cnt1) {
      cout << "0\n";
    } else if (cnt0 == cnt1 || s == "0") {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
}


