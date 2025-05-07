// time-limit: 3000
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
#define int long long

const int N = (int) 2e5 + 5, INF = (int) 2e9;
int stA[4 * N], stB[4 * N];
int a[N], b[N];
void build(int id, int l, int r) {
  if(l == r) {
    stA[id] = a[l], stB[id] = b[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id * 2, l, mid);
  build(id * 2 | 1, mid + 1, r);
  stA[id] = max(stA[id * 2], stA[id * 2 | 1]);
  stB[id] = min(stB[id * 2], stB[id * 2 | 1]);
}

pair<int, int> get(int id, int l, int r, int u, int v) {
  if(v < l || r < u) {
    return {0ll, INF};
  }
  if(u <= l && r <= v) {
    return {stA[id], stB[id]};
  }
  int mid = (l + r) >> 1;
  auto [g1f, g1s] = get(id * 2, l, mid, u, v);
  auto [g2f, g2s] = get(id * 2 | 1, mid + 1, r, u, v);
  return {max(g1f, g2f), min(g1s, g2s)};
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    for(int i = 0; i < 4 * n + 5; i++) stA[i] = INF, stB[i] = 0;
    map<int, vector<int>> pos;
    for(int i = 0; i < n; i++) cin >> a[i], pos[a[i]].push_back(i);
    for(int i = 0; i < n; i++) cin >> b[i];
    build(1, 0, n - 1);
    bool ok = true;
    for(int i = 0; i < n; i++) {
      if(a[i] > b[i]) {
        ok = false;
        cout << "NO\n";
        break;
      }
    }
    if(!ok) continue;
    for(int i = 0; i < n; i++) {
      if(a[i] > b[i]) {
        ok = false;
        break;
      }
      if(a[i] < b[i]) {
        //b[i] > b[j] -> if we make changes, then we can't not set a[j] to b[j]
        //a[j] > b[i] -> then if we set the max value it will set to a[j] instead of b[i]
        //both of this need to be satisfies
        //b[i] <= b[j] for all j from i + 1 to id or from id to i - 1
        //b[i] >= a[j] for all j from i + 1 to id or from id to i - 1
        bool can = false;
        auto p = lower_bound(pos[b[i]].begin(), pos[b[i]].end(), i);
        if(p != pos[b[i]].end()) {
          int id = *p;
          auto [maxaj, minbj] = get(1, 0, n - 1, i + 1, id);
          if(b[i] <= minbj && maxaj <= b[i]) {
            can = true;
          }
          //dbg(i, id, maxaj, minbj);
        }
        if(p != pos[b[i]].begin()) {
          int id = *prev(p);
          auto [maxaj, minbj] = get(1, 0, n - 1, id, i - 1);
          if(b[i] <= minbj && maxaj <= b[i]) {
            can = true;
          }
          //dbg(id, i, maxaj, minbj);
        }
        if(!can) {ok = false; break;}
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


