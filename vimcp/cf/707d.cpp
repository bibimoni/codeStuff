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

const int N = (int) 1e5 + 5, M = 1e3 + 5;
int n, m, q;
int ans[N];

struct Query {
  int type, i, j;
  Query(int _type, int _i, int _j) {
    type = _type;
    i = _i;
    j = _j;
  }
};

vector<pair<int, Query>> adj[N];
bitset<1024> bs[M];

void dfs(int u, int curr = 0) {
  ans[u] = curr;
  for(auto [idx, q] : adj[u]) {
    if(q.type == 1) {
      bool tmp = bs[q.i][q.j];
      curr -= tmp;
      bs[q.i].set(q.j, 1);
      curr++;
      dfs(idx, curr);
      curr += tmp;
      curr--;
      bs[q.i].set(q.j, tmp);
    } 
    else if(q.type == 2) {
      bool tmp = bs[q.i][q.j];
      curr -= tmp;
      bs[q.i].set(q.j, 0);
      dfs(idx, curr);
      curr += tmp;
      bs[q.i].set(q.j, tmp);
    }
    else if(q.type == 3) {
      int prev = bs[q.i].count();
      for(int i = 1; i <= m; i++) bs[q.i].flip(i);
      bs[q.i].set(0, 0);
      curr -= prev;
      curr += bs[q.i].count();
      dfs(idx, curr);
      curr += prev;
      curr -=  bs[q.i].count();
      for(int i = 1; i <= m; i++) bs[q.i].flip(i);
      bs[q.i].set(0, 0);
    }
    else if(q.type == 4) {
      dfs(idx, curr);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m >> q;
  int prev = 0;
  for(int i = 1; i <= q; i++) {
    int type; cin >> type;
    if(type == 1 || type == 2) {
      int x, y; 
      cin >> x >> y;
      adj[prev].push_back({i, {type, x, y}});
    }
    else if(type == 3) {
      int x;
      cin >> x;
      adj[prev].push_back({i, {type, x, -1}});
    }
    else if(type == 4) {
      int k; cin >> k;
      prev = k;
      adj[prev].push_back({i, {type, -1, -1}});
    }
    prev = i;
  }
  dfs(0);
  for(int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
}

