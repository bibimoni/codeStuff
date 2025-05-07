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
    int h = 0, v = 0;
    for(char c : s) {
      if(c == 'N')
        v++;
      if(c == 'S')
        v--;
      if(c == 'E')
        h++;
      if(c == 'W')
        h--;
    }
    if((h & 1) || (v & 1)) {
      cout << "NO\n";
      continue;
    }
    vector<char> ans(n);
    h /= 2, v /= 2;
    int ok = 0;
    auto go = [&] (char c1, char c2) -> void {
      vector<pair<char, int>> t;
      for(int i = 0; i < n; i++) {
        if(s[i] == c1 || s[i] == c2) {
          t.push_back({s[i], i});
        }
      }
      sort(t.begin(), t.end());
      vector<pair<char, int>> m;
      for(int i = 0; i < t.size() - i; i++) {
        m.push_back(t[i]);
        m.push_back(t[t.size() - i - 1]);
      }
      int curr = 0;
      int id;
      for(auto [c, i] : m) {
        if(c == c1) {
          curr++;
        }
        if(c == c2) {
          curr--;
        }
        if((curr == v && c1 == 'N') || (curr == h && c1 == 'E')) {
          id = i;
          break;
        }
      }
      for(auto [c, i] : m) {
        if(c == c1) {
          curr++;
        }
        if(c == c2) {
          curr--;
        }
        ans[i] = (!ok ? 'R' : 'H');
        if(id == i)
          ok ^= 1;
      }
    };
    go('N', 'S');
    go('E', 'W');
    if(count(ans.begin(), ans.end(), 'R') == 0 || count(ans.begin(), ans.end(), 'H') == 0) {
      cout << "NO\n";
      continue;
    }
    for(char i : ans)
      cout << i;
    cout << '\n';
  }
}


