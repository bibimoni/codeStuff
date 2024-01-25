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

struct Node {
    int lazy; 
    int val; 
} nodes[N * 4];

void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;
    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;
    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -2000111000;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id);

    return max(get(id*2, l, mid, u, v),
        get(id*2+1, mid+1, r, u, v));
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n;
  for(int x, i = 1; i <= n; i++) {
    cin >> x;
    update(1, 1, n, i, i, x);
  }
  MULTI {
    int type; cin >> type;
    int l, r; cin >> l >> r;
    if(type == 1) {
      int val; cin >> val;
      update(1, 1, n, l, r, val);
    }
    else if(type == 2) {
      cout << get(1, 1, n, l, r) << endl;
    }
  }
}





