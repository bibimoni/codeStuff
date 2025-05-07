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
  int q;
  cin >> q;
  vector<pair<int, int>> query(q + 1);
  for(int i = 1; i <= q; i++) {
    cin >> query[i].first >> query[i].second;
  }
  map<int, vector<int>> f;
  int add = 0;
  for(int i = 1; i <= q; i++) {
    auto [t, x] = query[i];
    if(t == 1) {
      f[x - add].push_back(i);
    }
    if(t == 2) {
      add += x;
    }
    if(t == 3) {
      f[x - add].clear();
    }   
  }
  //1 - 0 2 - 0 3 - 0 erase 3 - 0 add 1 3 - 1
  vector<pair<int, int>> save;
  for(auto [k, p] : f) {
    for(auto i : p) {
      save.push_back({i, k + add});
    }
  }
  sort(save.begin(), save.end());
  cout << save.size() << '\n';
  for(auto [_, v] : save) {
    cout << v << ' ';
  }
}


