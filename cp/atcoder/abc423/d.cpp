/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  map<int, vector<pair<int, int>>> events;
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
    events[a[i]].push_back({i, 0});
  }

  queue<int> que;
  vector<int> ans(n);
  int cur = 0;
  while (s.size()) {
    int time = *s.begin();
    s.erase(s.begin());
    for (auto p : events[time]) {
      if (p.second == 0) {
        que.push(p.first);
      } else {
        cur -= c[p.first];
      }
    }

    while (que.size() && cur <= k) {
      if (c[que.front()] + cur <= k) {
        cur += c[que.front()];
        ans[que.front()] = time;
        events[time + b[que.front()]].push_back({que.front(), 1});
        s.insert(time + b[que.front()]);
        que.pop();
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
}
