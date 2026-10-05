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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;

  vector<int> state(n);
  char no_c = 'a';
  set<int> no;
  for (int i = 0; i < n; i++) {
    no.insert(i);
  }

  vector<char> yes(n, ' ');
  vector<char> no_t(n, ' ');
  set<int> no_idx;

  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x;
      cin >> x;
      x -= 1;
      if (state[x] == 1) {
        char c = yes[x];
        if (c == no_c) {
          no.insert(x);
        } else {
          no_t[x] = c;
          no_idx.insert(x);
        }
        yes[x] = ' ';
      } else {
        if (no.find(x) != no.end()) {
          yes[x] = no_c;
          no.erase(x);
        } else {
          yes[x] = no_t[x];
          no_t[x] = ' ';
          no_idx.erase(x);
        }
      }
      state[x] ^= 1;
    } else {
      char nxt;
      cin >> nxt;
      no_c = nxt;
      for (int i : no_idx) {
        no.insert(i);
        no_t[i] = ' ';
      }
      no_idx = set<int>();
    }
  }

  vector<char> ans(n);
  for (int i : no) {
    ans[i] = no_c;
  }
  for (int i = 0; i < n; i++) {
    if (yes[i] != ' ') {
      ans[i] = yes[i];
    } 
    if (no_t[i] != ' ') {
      ans[i] = no_t[i];
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
}
