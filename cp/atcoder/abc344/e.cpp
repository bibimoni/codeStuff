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
  int n;
  cin >> n;
  int a[n + 1];
  set<int> s;
  map<int, int> nxt, prev;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  for(int i = 2; i <= n; i++) {
    prev[a[i]] = a[i - 1];
  }
  for(int i = 1; i < n; i++) {
    nxt[a[i]] = a[i + 1];
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int t;
    cin >> t;
    if(t == 1) {
      int x, y;
      cin >> x >> y;
      int nxtX = nxt[x], prevX = prev[x];
      nxt[x] = y;
      nxt[y] = nxtX;
      prev[y] = x;
      prev[nxtX] = y;
      s.insert(y);
    }
    else if(t == 2) {
      int x;
      cin >> x;
      if(prev[x]) {
        if(nxt[x]) {
          int nxtX = nxt[x], prevX = prev[x];
          prev[nxtX] = prevX;
          nxt[prevX] = nxtX;
          nxt[x] = 0;
          prev[x] = 0;
        }
        else {
          int prevX = prev[x];
          nxt[prevX] = 0;
        }
        prev[x] = 0;
      }
      if(nxt[x]) {
        if(!prev[x]) {
          prev[nxt[x]] = 0;
          nxt[x] = 0;
          prev[x] = 0;
        }
        nxt[x] = 0;
      }
      s.erase(x);
    }
  }
  int start = -1;
  for(int i : s) {
    if(prev[i] == 0 && nxt[i] != 0) {
      start = i;
      break;
    }
  }
  if(start != -1) {
    cout << start << ' ';
    for(int i = nxt[start]; i != 0; i = nxt[i]) {
      cout << i << ' ';
    }
  }
  else {
    cout << *s.begin();
  }
}


