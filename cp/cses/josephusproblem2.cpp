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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  set<int> s;
  for(int i = 1; i <= n; i++) {
    s.insert(i);
  }
  auto it = s.begin();
  while(s.size() > 1) {
    if(it == s.end()) {
      cout << *next(s.begin()) << ' ';
      s.erase(next(s.begin()));
      it = next(s.begin());
    }
    else if(next(it) != s.end()) {
      cout << *next(it) << ' ';
      s.erase(next(it));
      it = next(it);
    }
    else if(next(it) == s.end()) {
      cout << *s.begin() << ' ';
      s.erase(s.begin());
      it = s.begin();
    }
  }
  cout << *s.begin();
}

