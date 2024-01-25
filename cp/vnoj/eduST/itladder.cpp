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

const int N = (int) 1e5 + 5, MOD = (int) 1e9 + 7;

int it[4 * N], itIA[4 * N], itBLA[4 * N], a[N];

int add(int a, int b) {
  return (a % MOD + b % MOD + MOD) % MOD;
}

int mul(int a, int b) {
  return (a % MOD * b % MOD) % MOD;
}

int sumLR(int l, int r) {
  return add((r * (r + 1) / 2), -(l * (l - 1) / 2));
}

void down(int id, int l, int r) {
  if(itIA[id] == 0 && itBLA[id] == 0) return;
  int mid = (l + r) >> 1;
  int ia = itIA[id] / sumLR(l, r), ibla = itBLA[id] / (r - l + 1);
  itIA[id * 2] = add(itIA[id * 2], sumLR(l, mid) * ia);
  itIA[id * 2 | 1] = add(itIA[id * 2 | 1], sumLR(mid + 1, r) * ia);
  itBLA[id * 2] = add(itBLA[id * 2], mul((mid - l + 1), ibla));
  itBLA[id * 2 | 1] = add(itBLA[id * 2 | 1], mul((r - mid), ibla));
  it[id * 2] = add(it[id * 2], add(itIA[id * 2], itBLA[id * 2]));
  it[id * 2 | 1] = add(it[id * 2 | 1], add(itIA[id * 2 | 1], itBLA[id * 2 + 1]));
  itIA[id] = 0;
  itBLA[id] = 0;
}

void update(int id, int l, int r, int u, int v, int a, int b) {
  if(v < l || r < u) return;
  if(u <= l && r <= v) {
    itIA[id] += mul(sumLR(l, r), a);
    itBLA[id] += mul((r - l + 1), (b - u * a));
    it[id] += add(mul(sumLR(l, r), a), mul((r - l + 1), (b - u * a)));
    return;
  }
  down(id, l, r);
  int mid = (l + r) >> 1;
  update(id << 1, l, mid, u, v, a, b);
  update(id << 1 | 1, mid + 1, r, u, v, a, b);
  it[id] = add(it[id << 1], it[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v) {
  if(v < l || r < u) return 0;
  if(u <= l && r <= v) {
    return it[id] % MOD;
  }
  down(id, l, r);
  int mid = (l + r) >> 1;
  return add(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  MULTI {
    int type; cin >> type;
    if(type == 1) {
      int l, r, a, b; cin >> l >> r >> a >> b;
      update(1, 1, n, l, r, a, b);
    }
    else {
      int l, r; cin >> l >> r;
      cout << get(1, 1, n, l, r) << endl;
    }
  }
}



