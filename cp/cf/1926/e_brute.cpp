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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n = 100;
  vector<pair<int, int>> a;
  set<int> s;
  int c = 1;
  int id = 1;
  while(a.size() != n) {
    if(s.find(c * id) == s.end()) {
      s.insert(c * id);
      a.push_back({c, c * id});
    }
    id += 2;
    if(id > n || c * id > n) {
      id = 1;
      c++;
    }
  }
  dbg(a);
}

