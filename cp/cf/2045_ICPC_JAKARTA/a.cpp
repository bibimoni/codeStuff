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
  int cons = 0, vows = 0, ys = 0, ns = 0, gs = 0;
  string s;
  cin >> s;
  const string v = "AIUEO";
  for (char c : s) {
    if (c == 'Y') {
      ys += 1;
      continue;
    } 
    if (c == 'G') {
      gs += 1;
    }
    if (c == 'N') {
      ns += 1;
    }
    bool f = false;
    for (char cv : v) {
      if (cv == c) {
        vows += 1;
        f = true;
      }
    }
    cons += int(!f);
  }
  int ngs = min(ns, gs);
  int ans = 0;
  for (int ng = 0; ng <= ngs; ng++) {
    for (int y = 0; y <= ys; y++) {
      int ncons = cons - 2 * ng + y;
      int nvows = vows + ys - y;
      int ngwords = min(ng / 2, nvows);
      int kng = ng - 2 * ngwords;
      nvows -= ngwords;
      ncons += kng;
      int words = min(ncons / 2, nvows);
      int len = 5 * ngwords + 3 * words + min(kng, words);
      ans = max(ans, len);
    }
  }
  cout << ans << '\n';
}

