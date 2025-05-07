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
    int n, m, k;
    cin >> n >> m >> k;
    set<int> a, b;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    for(int i = 0; i < m; i++) {
      int x;
      cin >> x;
      b.insert(x);
    }
    int cnta = 0, cntb = 0;
    set<int> picked;
    for(int i : a) {
      if(i > k || cnta >= k / 2) {
        break;
      }
      if(b.find(i) == b.end()) {
        picked.insert(i);
        cnta++;
      }
    }
    dbg(picked, cnta);
    for(int i : b) {
      if(i > k || cntb >= k / 2) {
        break;
      }
      if(a.find(i) == a.end()) {
        picked.insert(i);
        cntb++;
      }
    }
    dbg(picked, cntb);
    if(picked.size() < k) {
      for(int i : a) {
        if(i > k || cnta >= k / 2) {
          break;
        }
        if(b.find(i) != b.end()) {
          picked.insert(i);
          cnta++;
        }
      }
    }
    if(picked.size() < k) {
      for(int i : b) {
        if(i > k || cntb >= k / 2) {
          break;
        }
        if(a.find(i) != a.end() && picked.find(i) == picked.end()) {
          picked.insert(i);
          cntb++;
        }
      }
    }
    dbg(picked, a, b);
    int curr = 1;
    for(int i : picked) {
      if(i == curr) {
        curr++;
      }
    }
    if(curr == k + 1) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}


