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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    vector<int> cnt2(26);
    for (int i = 2; i < n; i++) {
      cnt2[s[i] - 'a'] += 1;
    }
    vector<int> cnt1(26);
    cnt1[s[0] - 'a'] += 1;
    for (int i = 1; i + 1 < n; i++) {
      if (cnt1[s[i] - 'a'] > 0 || cnt2[s[i] - 'a'] > 0) {
        dbg(s[i], cnt1[s[i] - 'a'], cnt2[s[i] - 'a']);
        ok = true;
      }
      cnt1[s[i] - 'a'] += 1;
      cnt2[s[i + 1] - 'a'] -= 1;
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}
