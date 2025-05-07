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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  a[0] = {0, 0};
  for(int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for(int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  sort(a.begin() + 1, a.end(), [&] (pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
  });
  priority_queue<int, vector<int>, greater<int>> pq;
  multiset<int> s;
  int curr = 0, cnt = 0;
  for(int i = 1; i <= n; i++) {
    pq.push(a[i].second);
    cnt++;
    curr += a[i].second;
    if(cnt > a[i].first) {
      cnt--;
      curr -= pq.top();
      pq.pop();
    }
  }
  cout << curr;
}
