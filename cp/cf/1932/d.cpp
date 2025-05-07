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
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    vector<string> card(2 * n);
    for(int i = 0; i < 2 * n; i++) {
      cin >> card[i];
    }
    vector<vector<int>> ids(2 * n);
    for(int i = 0; i < 2 * n; i++) {
      for(int j = 0; j < 2 * n; j++) {
        if(i == j)
          continue;
        if(card[i][1] == trump) {
          if(card[j][1] != trump) {
            ids[i].push_back(j);
          }
          else if(card[j][0] < card[i][0]) {
            ids[i].push_back(j);
          }
        }
        else {
          if(card[i][1] == card[j][1] && card[i][0] > card[j][0]) {
            ids[i].push_back(j);            
          }
        }
      }
    }
    vector<int> p(2 * n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&] (int i, int j) {
      return ids[i].size() > ids[j].size();
    });
    vector<int> mark(2 * n, 0);
    vector<array<int, 2>> ans;
    bool ok = true;
    for(int i = 0; i < p.size(); i++) {
      int id = p[i];
      // dbg(ids[id], card[id]);
      if(!ids[id].size())
        continue;
      mark[id] = true;
      for(auto j : ids[id]) {
        if(mark[j])
          continue;
        ans.push_back({j, id});
        mark[j] = true;
        ok = true;
        break;
      }
    }
    if(!ok || ans.size() != n) {
      cout << "IMPOSSIBLE\n";
    }
    else {
      for(auto [f, s] : ans) {
        cout << card[f] << ' ' << card[s] << '\n';
      }
    }
  }
}


