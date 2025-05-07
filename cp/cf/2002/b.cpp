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
    deque<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    deque<int> b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b.push_back(x);
    }
    while (a.size() > 1 && b.size() > 1) {
      bool out = false;
      int rem = -1;
      for (int i : {int(0), (int) a.size() - 1}) {
        if (out) {
          break;
        }
        bool diff = true;
        for (int j : {int(0), (int) b.size() - 1}) {
          diff &= a[i] != b[j];
        }
        if (diff) {
          if (i == 0) {
            rem = a[0];
            a.pop_front();
          } else {
            rem = a.back();
            a.pop_back();
          }
          out = true;
          break;
        }
      }
      if (!out) {
        rem = a.back();
        a.pop_back();
      }
      assert(rem != -1);
      out = false;
      for (int j : {int(0), (int) b.size() - 1}) {
        if (b[j] == rem) {
          if (j == 0) {
            b.pop_front();
          } else {
            b.pop_back();
          }
          out = true;
          break;
        }
      }
      if (!out) {
        for (int j : {int(0), (int) b.size() - 1}) {
          if (out) {
            break;
          }
          for (int i : {int(0), (int) a.size() - 1}) {
            if (a[i] == b[j]) {
              if (j == 0) {
                b.pop_front();
              } else {
                b.pop_back();
              }
              out = true;
              break;
            }
          }
        }
      }
      if (!out) {
        b.pop_back();
      }  
    }
    cout << (a[0] == b[0] ? "Bob\n" : "Alice\n");
  }
}


