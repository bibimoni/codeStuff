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

const int N = (int) 5e5 + 5;

int st[4 * N], lazy[4 * N], v[N], n, q;

void build(int id = 1, int l = 1, int r = n) {
  lazy[id] = 0;
  if(l == r) {
    st[id] = v[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id * 2, l, mid);
  build(id * 2 | 1, mid + 1, r);
  st[id] = max(st[id * 2], st[id * 2 | 1]);
}

void down(int id) {
  if(lazy[id] == 0) return;
  st[id * 2] += lazy[id];
  st[id * 2 | 1] += lazy[id];
  lazy[id * 2] += lazy[id];
  lazy[id * 2 | 1] += lazy[id];
  lazy[id] = 0;
}

void add(int u, int v, int val, int id = 1, int l = 1, int r = n) {
  if(v < l || r < u) return;
  if(u <= l && r <= v) {
    lazy[id] += val;
    st[id] += val;
    return;
  }
  down(id);
  int mid = (l + r) >> 1;
  add(u, v, val, id * 2, l, mid);
  add(u, v, val, id * 2 | 1, mid + 1, r);
  st[id] = max(st[id * 2], st[id * 2 | 1]);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> q;
  int tmpA[n + 1], tmpB[n + 1];
  vector<int> a, b; int c[n + 1];
  for(int i = 1; i <= n; i++) cin >> tmpA[i];
  for(int i = 1; i <= n; i++) cin >> tmpB[i];
  for(int i = 1; i < n; i++) cin >> c[i];
  int j = 1;
  a.push_back(0); b.push_back(0);
  for(int i = 1; i <= 2 * n - 1; i++) {
    if(i & 1) {
      a.push_back(tmpA[j]);
      b.push_back(tmpB[j]);
    }
    else {
      a.push_back(c[j++]);
      b.push_back(0);
    }
  }
  dbg(a, b);
  n = a.size() - 1;
  vector<int> preA(n + 1, 0), preB(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    preA[i] = preA[i - 1] + a[i];
    preB[i] = preB[i - 1] + b[i];
    v[i] = preB[i] - preA[i];
  }
  build();
  int totalB = preB[n];
  while(q--) {
    int p, x, y, z; cin >> p >> x >> y >> z;
    p = 1 + 2 * (p - 1);
    totalB += -b[p] + y;
    int diff =  -(x - a[p]) + (y - b[p]);
    add(p, n, diff);
    cout << totalB - max(0ll, st[1]) << '\n';
    b[p] = y;
    a[p] = x;
    if(p != n) a[p + 1] = z;
  }
}


