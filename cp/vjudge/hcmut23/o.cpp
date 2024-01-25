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

const int N = (int) 1e5 + 1, INF = (int) 2e9;
int n;
int st[4 * N];

void update(int node, int l, int r, int i, int val) {
  if(i < l || r < i) return;
  if(l == r) {
    st[node] = val;
    return;
  }
  int mid = (l + r) >> 1;
  update(node * 2, l, mid, i, val);
  update(node * 2 | 1, mid + 1, r, i, val);
  st[node] = st[2 * node] + st[2 * node | 1];
}

int get(int node, int l, int r, int u, int v) {
  if(v < l || r < u) {
    return 0;
  }
  if(u <= l && r <= v) {
    return st[node];
  }
  int mid = (l + r) >> 1;
  return get(node * 2, l, mid, u, v) + get(node * 2 | 1, mid + 1, r, u, v);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n;
  MULTI {
    int type, a, b; cin >> type >> a >> b;
    if(type == 1) {
      update(1, 1, n, a, b);
    }
    else if(type == 2) {
      cout << get(1, 1, n, a, b) << endl;
    }
  }
}




