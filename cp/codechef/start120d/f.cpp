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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n * 2 + 1];
    vector<int> pos(n + 1, 0);
    vector<pair<int, int>> dis;
    for(int i = 1; i <= 2 * n; i++) {
      cin >> a[i];
      if(!pos[a[i]]) {
        pos[a[i]] = i;
      }
      else {
        dis.push_back({i - pos[a[i]] + 1, a[i]});
      }
    }
    sort(dis.begin(), dis.end(), greater<pair<int, int>>());
    for(int i = 0; i < dis.size(); i++) {
      cout << dis[i].second << " \n"[i == dis.size() - 1];
    }
  }
}

