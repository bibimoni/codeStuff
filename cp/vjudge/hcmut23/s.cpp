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

const int N = (int) 1e5 + 5;
int n;
int bound = 0;
struct Query {
  int x, y1, y2, val;
};
vector<Query> a;

struct Node {
  int len, cnt;
};

Node st[4 * N];

void update(int id, int l, int r, int u, int v, int type) {
  if(v < l || r < u || v < u) return;
  if(u <= l && r <= v) {
    st[id].cnt += type;
  }
  else {
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, type);
    update(id * 2 | 1, mid + 1, r, u, v, type);
  }
  if(st[id].cnt == 0) {
    st[id].len = st[id * 2].len + st[id * 2 | 1].len;
  }
  else {
    st[id].len = r - l + 1;
  }
}

int solveRect() {
  sort(all(a), [&] (Query x, Query y) {
    return x.x < y.x;
  });
  int ans = 0;
  for(int i = 0; i < sz(a) - 1; i++) {
    update(1, 1, bound, a[i].y1, a[i].y2, a[i].val);
    ans += st[1].len * (a[i + 1].x - a[i].x);
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n;
  for(int x1, y1, x2, y2, i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    a.pb({x1, y1 + 1, y2, 1});
    a.pb({x2, y1 + 1, y2, -1});
    bound = max(bound, y2 + 1);
  }
  cout << solveRect();
}



