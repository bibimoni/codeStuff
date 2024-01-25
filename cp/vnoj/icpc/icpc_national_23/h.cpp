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
#define all(x)         x.begin(), x.end()

const int N = (int) 2e5 + 5;
vector<int> pos[N];
struct BIT { 
  int _n;
  vector<int> ft;
  void init(int n) {
    _n = n;
    ft.resize(_n + 5);
  }
  void update(int id, int val) {
    for(; id < _n + 5; id += (id & -id)) ft[id] += val;
  }
  int get(int id) {
    int ans = 0;
    for(; id > 0; id -= (id & -id)) ans += ft[id];
    return ans;
  }
  int range(int l, int r) {
    return (get(r) - (l == 0 ? 0 : get(l - 1)));
  }
};

vector<BIT> fts(N);
vector<map<int, int>> idx(N);
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q; cin >> n >> q;
  int a[n + 1];
  vector<bool> check(N, false);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  dbg("POS");
  for(int i = 1; i <= n; i++) {
    if(check[a[i]]) continue;
    check[a[i]] = true;
    int j = 0;
    fts[a[i]].init(pos[a[i]].size());
    for(int v : pos[a[i]]) {
      fts[a[i]].update(++j, v * v);
      idx[a[i]][v] = j;
      dbg(idx[a[i]][v], v, j);
    }
  }
  dbg("UPDATE BIT");
  int last = 0;
  dbg("START QUERY");
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      dbg("GO TO QUERY 1");
      int p; cin >> p;
      p = (p + last - 1) % (n - 1) + 1;
      if(a[p] == a[p + 1]) continue;
      int id1 = idx[a[p]][p];
      int id2 = idx[a[p + 1]][p + 1];
      idx[a[p]].erase(p);
      idx[a[p]][p + 1] = id1;
      idx[a[p + 1]].erase(p + 1);
      idx[a[p + 1]][p] = id2;
      pos[a[p]][id1 - 1] = p + 1;
      pos[a[p + 1]][id2 - 1] = p;
      fts[a[p]].update(id1, (p + 1) * (p + 1) - (p * p));
      fts[a[p + 1]].update(id2, -(p + 1) * (p + 1) + (p * p));
      swap(a[p], a[p + 1]);
      //dbg("QUERY 1 FINISHED");
      //dbg("ASK FOR INDEX 6, 7");
      //dbg(idx[a[p]], idx[a[p + 1]]);
      //dbg(pos[a[p]], pos[a[p + 1]]);
      //dbg(id1, id2);
    }
    else if(t == 2 || t == 3) {
      int l, r, x;
      cin >> l >> r >> x;
      l = (l + last - 1) % n + 1;
      r = (r + last - 1) % n + 1;
      x = (x + last - 1) % n + 1;
      if(l > r) swap(l, r);
      if(t == 3) {
        dbg("GOTO QUERY 3");
        dbg(l, r);
        int ans = fts[x].range(l, r);
        cout << ans << '\n';
        last = ans;
      }
      else if(t == 2) {
        dbg("GOTO QUERY 2", l, r);
        auto it = upper_bound(all(pos[x]), r);
        it = prev(it); int id2 = it - pos[x].begin();
        int id1 = lower_bound(all(pos[x]), l) - pos[x].begin();
        dbg(id1, id2, pos[x]);
        if(l > r) {
          cout << 0 << '\n';
          last = 0;
        }
        int ans = fts[x].range(id1 + 1, id2 + 1);
        cout << ans << '\n';
        last = ans;
      }
    }
  }
}

 