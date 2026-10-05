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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = int(s.size());
    vector<int> cnt(26, 0);
    for (char c : s) {
      cnt[c - 'a'] += 1;
    }
    vector<char> c(26);
    iota(c.begin(), c.end(), 'a');
    sort(c.begin(), c.end(),
         [&](char x, char y) { return cnt[x - 'a'] > cnt[y - 'a']; });

    string t = "";
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      char ci = c[i];
      if (cnt[ci - 'a'] * 2 < n) {
        continue;
      }
      for (int j = i + 1; j < 26; j++) {
        char cj = c[j];
        int mn = min(cnt[ci - 'a'], cnt[cj - 'a']);
        cnt[ci - 'a'] -= mn;
        cnt[cj - 'a'] -= mn;
        for (int k = 0; k < mn; k++) {
          t += ci;
          t += cj;
        }
      }
      if (cnt[ci - 'a'] == 1) {
        t += ci;
        cnt[ci - 'a'] -= 1;
      }
      if (cnt[ci - 'a'] > 1) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "No\n";
      continue;
    }
    dbg(t);

    while (c.size() && cnt[c.back() - 'a'] == 0) {
      c.pop_back();
    }

    int ALP = (int)c.size();
    for (int i = ALP - 1; i >= 0; i--) {
      string cur = "";
      cur += c[i];
      int freq = cnt[c[i] - 'a'];
      cnt[c[i] - 'a'] = 0;
      for (int j = i - 1; j >= 0; j--) {
        cur += c[j];
        cnt[c[j] - 'a'] -= freq;
      }

      for (int k = 0; k < freq; k++) {
        t += cur;
      }
    }
    for (int i = 0; i + 1 < int(t.size()); i++) {
      ok &= t[i] != t[i + 1];
    }

    if (t.size() != s.size() || !ok) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    cout << t << '\n';
  }
}
