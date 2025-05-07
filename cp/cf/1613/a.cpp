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
  int tt;
  cin >> tt;
  while (tt--) {
    int x, p1;
    cin >> x >> p1;
    int x2, p2;
    cin >> x2 >> p2;
    auto len = [&] (int num) {
      int tmp = 0;
      while (num != 0) {
        tmp += 1;
        num /= 10;
      }
      return tmp;
    };
    int l1 = len(x), l2 = len(x2);
    if (l1 + p1 != l2 + p2) {
      cout << (l1 + p1 < l2 + p2 ? "<\n" : ">\n");
    } else {
      string s1 = to_string(x), s2 = to_string(x2);
      if (l1 > l2) {
        s2 += string(l1 - l2, '0');
      } else if (l1 < l2) {
        s1 += string(l2 - l1, '0');
      }
      dbg(s1, s2);
      bool ok = false;
      for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i]) {
          cout << "<\n";
          ok = true;
          break;
        } 
        if (s1[i] > s2[i]) {
          cout << ">\n";
          ok = true;
          break;
        }
      }
      if (!ok) {
        cout << "=\n";
      }
    }
  }
}

