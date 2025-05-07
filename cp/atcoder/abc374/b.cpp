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
  string t;
  cin >> t;
  int id = 0;
  for (int i = 0; i < min(t.size(), s.size()); i++) {
    if (s[i] != t[i]) {
      id = i + 1;
      break;
    }
  }
  if (!id && s.size() < t.size()) {
    id = s.size() + 1;
  } else if (!id && s.size() > t.size()) {
    id = t.size() + 1;
  }
  cout << id;
}


