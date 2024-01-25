/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 09.10.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define makeUnique(x)  sort(all(x)); x.erase(unique(all(x)), x.end());
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
#define Close          -1
#define Open           1
const int 
      MAXN = (int) 1e6 + 5, 
      INF = (int) 1e18, 
      MOD = (int) 1e9 + 7; //998244353
inline int nxt() { int n; cin >> n; return n; }

const int BOUND = (int) 1e18;

struct Node {
  int cnt, len;
};

struct Rect {
  int x1, y1, x2, y2;
};

struct Event {
  int x, type, y1, y2;
};

map<int, Node> st;
int k, n;
vector<Rect> rects;

void update(int k, int l, int r, int i, int j, int val) {
  if(r <= i || l >= j) return;
  if(i <= l && r <= j) {
    st[k].cnt += val;
  }
  else {
    int mid = (l + r) >> 1;
    update(k << 1, l, mid, i, j, val);
    update(k << 1 | 1, mid, r, i, j, val);
  }
  if(st[k].cnt == 0 && l < r) {
    st[k].len = st[k << 1].len + st[k << 1 | 1].len;
  }
  else {
    st[k].len = r - l;
  }
}

int countArea() {
  vector<Event> events;  
  for(int i = 0; i < sz(rects); i++) {
    events.pb({rects[i].x1, Open, rects[i].y1, rects[i].y2});
    events.pb({rects[i].x2, Close, rects[i].y1, rects[i].y2});
  }
  sort(all(events), [&] (Event a, Event b) {
    return a.x < b.x;
  });
  int ans = 0;
  for(int i = 0, y1, y2, type, len, d; i < sz(events) - 1; i++) {
    y1 = events[i].y1; y2 = events[i].y2;
    type = events[i].type;
    update(1, -BOUND, BOUND, y1, y2, type);
    len = events[i + 1].x - events[i].x;
    d = st[1].len;
    //cout << len << ' ' << d << endl;
    ans += len * d;
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> k >> n;
  int x = 0, y = 0;
  for(int i = 0; i < n; i++) {
    char dir; cin >> dir;
    int d; cin >> d;
    int newX = x, newY = y;
    if(dir == 'E') newX += d;
    else if(dir == 'N') newY += d;
    else if(dir == 'W') newX -= d;
    else if(dir == 'S') newY += d;
    rects.pb({min(newX, x), min(newY, y), max(newX, x) + k, max(newY, y) + k});  
    x = newX; y = newY;
  }
  cout << countArea();
}
