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
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> jobs(k);
    map<int, vector<int>> end;
    map<int, vector<int>> st;
    for (int i = 0; i < k; i++) {
      cin >> jobs[i].first >> jobs[i].second;
      end[jobs[i].second + 1].push_back(i);
      st[jobs[i].first].push_back(i);
    }
    vector<int> days(n + 1, 0);
    set<int> cur;
    int length = 0;
    pair<int, int> ans;
    int t1 = 0, t2 = int(1e9);
    for (int i = 1; i <= n; i++) {
      length += 1;
      for (int j : st[i]) {
        cur.insert(j);
      }  
      if (length < d) {
        continue;
      } else {
        for (int j : end[i - d + 1]) {
          cur.erase(j);
        }
        if (cur.size() > t1) {
          t1 = cur.size();
          ans.first = i - d + 1;
        }
        if (cur.size() < t2) {
          t2 = cur.size();
          ans.second = i - d + 1;
        }
      }
    }
    cout << ans.first << ' ' << ans.second << '\n';
  }
}


