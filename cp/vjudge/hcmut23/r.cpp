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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

const int N = (int) 1e5 + 1, INF = (int) 1e16;
int a[N];
multiset<int> st[4 * N];

multiset<int> merge(multiset<int> a, multiset<int> b){
	multiset<int> c;
	for (auto it = a.begin(); it != a.end(); ++it) c.insert(*it);
	for (auto it = b.begin(); it != b.end(); ++it) c.insert(*it);
	return c;
}

void build(int id, int l, int r) {
  if(l == r) {
    st[id].insert(a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(id * 2, l, mid);
  build(id * 2 | 1, mid + 1, r);
  st[id] = merge(st[id * 2], st[id * 2 | 1]);
}
int tmp = 0;
void update(int id, int l, int r, int i, int v) {
  if(i < l || r < i) return;
  if(l == r) {
    tmp = *st[id].begin();
    st[id].erase(st[id].begin());
    st[id].insert(v);
    return;
  }
  int mid = (l + r) >> 1;
  if(i <= mid) update(id * 2, l, mid, i, v);
  else update(id * 2 | 1, mid + 1, r, i , v);
  st[id].erase(st[id].find(tmp));
  st[id].insert(v);
}
int get(int id, int l, int r, int u, int v, int k) {
  if(v < l || r < u) return INF;
  if(u <= l && r <= v) {
    auto it = st[id].lower_bound(k);
    if(it != st[id].end()) return *it;
    return INF;
  }
  int mid = (l + r) >> 1;
  int p = get(id * 2, l, mid, u, v, k), q = get(id * 2 | 1, mid + 1, r, u, v, k);
  if(p > 0 && q > 0) return min(q, p);
  return max(p, q);
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  while(m--) {
    int type; cin >> type;
    if(type == 1) {
      int i, v; cin >> i >> v;
      update(1, 1, n, i, v);
    }
    else {
      int l, r, k; cin >> l >> r >> k;
      int t = get(1, 1, n, l, r, k);
      cout << (t == INF ? -1 : t) << endl;
    }
  }
}



