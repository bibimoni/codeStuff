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
  int n, r, q;
  double p;
  cin >> n >> r >> q >> p;
  map<int, vector<int>> f;
  map<pair<int, int>, int> idx;
  for(int i = 0; i < r; i++) {
    int u, v;
    cin >> u >> v;
    f[u].push_back(v);
    idx[{u, v}] = i;
  }
  vector<int> mark(r, 0);
  multiset<pair<int, int>> st;
  for(int i = 0; i < n; i++) {
    for(int v : f[i]) {
      st.insert({v, idx[{i, v}]});
    }
    while(st.size() && (*st.begin()).first < i) {
      st.erase(st.begin());
    }
    while(st.size()) {

    }
  }

}


