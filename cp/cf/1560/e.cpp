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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26);
    vector<char> order;
    for (int i = n - 1; i >= 0; i--) {
      if (cnt[s[i] - 'a'] == 0) {
        order.push_back(s[i]);
      }
      cnt[s[i] - 'a'] += 1;
    }
    int turns = order.size();
    bool ok = true;
    vector<int> turnCnt(26);
    for (char c : order) {
      if (cnt[c - 'a'] % turns != 0) {
        ok = false;
        break;
      }
      turnCnt[c - 'a'] = cnt[c - 'a'] / turns;
      turns -= 1;
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    int sz = 0;
    turns = order.size();
    for (char c : order) {
      sz += turnCnt[c - 'a'];
    }
    reverse(order.begin(), order.end());
    vector<char> used(26, 0);
    string b = s.substr(0, sz);
    int id = 0, m = sz;
    string sc = "";
    for (char c : order) {
      int j = 0;
      sc += c;
      for (int i = id; i < id + m; i++) {
        while (j + 1 < sz && used[b[j] - 'a']) {
          j += 1;
        }
        if (s[i] != b[j]) {
          ok = false;
          break;
        }
        j += 1;
      }
      if (!ok) {
        break;
      }
      used[c - 'a'] = 1;
      id += m;
      m -= turnCnt[c - 'a'];
    }    
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    cout << b << ' ' << sc << '\n';
  }  
}

