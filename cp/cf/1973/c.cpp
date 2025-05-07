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
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
      cin >> p[i];
    }
    auto getMax = [&] (vector<int> &q) -> int {
      int ret = 0;
      for(int i = 1; i < n - 1; i++) {
        ret += ((p[i] + q[i] > p[i - 1] + q[i - 1]) && (p[i] + q[i] > p[i + 1] + q[i + 1]));
      }
      return ret;
    };
    vector<pair<int, int>> evens;
    for(int i = 1; i < n - 1; i += 2) {
      evens.push_back({p[i], i});
    }
    sort(evens.begin(), evens.end());    
    vector<pair<int, int>> odds;
    for(int i = 2; i < n - 1; i += 2) {
      odds.push_back({p[i], i});
    }
    sort(odds.begin(), odds.end());
    int cntEvens = 0, cntOdds = 0;
    vector<int> qE(n, 0);
    //evens
    {
      int curr = n;
      for(int i = 0; i < evens.size(); i++) {
        qE[evens[i].second] = curr--;
      }
      auto d = odds;
      d.push_back({p[0], 0});
      d.push_back({p[n - 1], n - 1});
      sort(d.begin(), d.end());
      curr = 1;
      for(int i = d.size() - 1; i >= 0; i--) {
        qE[d[i].second] = curr++;
      }
      cntEvens = getMax(qE);
    }
    vector<int> qO(n, 0);
    //odds
    {
      int curr = n;
      for(int i = 0; i < odds.size(); i++) {
        qO[odds[i].second] = curr--;
      }
      curr = 1;
      auto d = evens;
      d.push_back({p[0], 0});
      d.push_back({p[n - 1], n - 1});
      sort(d.begin(), d.end());
      for(int i = d.size() - 1; i >= 0; i--) {
        qO[d[i].second] = curr++;
      }
      cntOdds = getMax(qO);
    }
    if(cntOdds > cntEvens) {
      for(int i : qO)
        cout << i << ' ';
    }
    else {
      for(int i : qE)
        cout << i << ' ';
    }
    cout << '\n';
  }
}


