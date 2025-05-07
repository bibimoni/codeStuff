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
    map<char, int> cnt;
    for (char c : s) {
      cnt[c] += 1;
    }
    vector<char> ans(n, '#');
    vector<pair<int, char>> p;
    for (auto [ch, o] : cnt) {
      p.push_back({o, ch});
    }
    sort(p.begin(), p.end());
    int l1 = n - 1, l2 = n - 2;
    bool cur = true;
    for (auto [o, ch] : p) {
      while (o--) {
        if (!cur) {
          if (l2 < 0) {
            ans[l1] = ch;
            l1 -= 2;
          } else {
            ans[l2] = ch;
            l2 -= 2;
          }          
        } else {
          if (l1 < 0) {
            ans[l2] = ch;
            l2 -= 2;
          } else {
            ans[l1] = ch;
            l1 -= 2;            
          }
        }
      } 
      cur = !cur;
    }
    for (char c : ans) {
      cout << c;
    }
    cout << '\n';
  }
}


