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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  map<int, vector<int>> occur, dist;
  map<int, int> last;
  set<int> items;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    items.insert(a[i]);
  }
  for(int i = 1; i <= n; i++) {
    if(last[a[i]]) {
      dist[a[i]].push_back(i - last[a[i]] - 1);
    }
    int tmp = 1;
    while(i + 1 <= n && a[i + 1] == a[i]) {
      i++;
      tmp++;
    }
    last[a[i]] = i;
    occur[a[i]].push_back(tmp);
  }
  //o....o....o]
  int ans = 0;
  for(int e : items) {
    auto occ = occur[e], d = dist[e];
    if(!d.size()) {
      ans = max(ans, occ[0]);
      continue;
    }
    int j = 0, sum = occ[j], tot = 0;
    for(int i = 1; i < occ.size(); i++) {
      while(tot > k) {
        sum -= occ[j];
        tot -= d[j];
        j++;
      }
      ans = max(ans, sum);
      sum += occ[i];
      tot += d[i - 1];
    }
    while(tot > k) {
      sum -= occ[j];
      tot -= d[j];
      j++;
    }
    ans = max(ans, sum);
  }
  cout << ans;
}


