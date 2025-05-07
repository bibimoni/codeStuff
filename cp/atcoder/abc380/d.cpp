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
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  int q;
  cin >> q;
  auto lb = [&] (int id) {
    int x = n;
    while (x * 2 < id) {
      x *= 2;
    }
    return x;
  };
  auto sw = [&] (char x) {
    if ('a' <= x && x <= 'z') {
      return x - 'a' + 'A';
    }
    return x - 'A' + 'a';
  };
  while (q--) {
    int k;
    cin >> k;
    bool cur = 0;
    while (k > n) {
      int del = lb(k);
      cur ^= 1;
      k -= del;
    }
    if (k <= n) {
      cout << char(cur == 0 ? s[k] : sw(s[k])) << ' ';
    }
  }
}


