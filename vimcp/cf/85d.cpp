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

const int N = (int) 1e5 + 5;

vector<int> s;
int st[4 * N][5], cnt[4 * N];

void update(int id, int l, int r, int pos, int type) {
  if(pos < l || r < pos) {
    return;
  }
  if(l == r) {
    if(type == 1) {
      cnt[id] = 1;
      st[id][0] = s[pos - 1];
    }
    else if(type == -1) {
      cnt[id] = 0;
      st[id][0] = 0;
    }
    return;
  }
  int mid = (l + r) >> 1;
  update(id * 2, l, mid, pos, type);
  update(id * 2 | 1, mid + 1, r, pos, type);
  cnt[id] = (cnt[id * 2] + cnt[id * 2 | 1]) % 5;
  for(int i = 0; i < 5; i++) {
    st[id][i] = st[id * 2][i] + st[id * 2 | 1][(i + 5 - cnt[id * 2]) % 5];
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> query;
  while(n--) {
    string t; cin >> t;
    if(t == "add") {
      int x;
      cin >> x;
      s.push_back(x);
      query.push_back({x, 1});
    }
    else if(t == "del") {
      int x;
      cin >> x;
      query.push_back({x, -1});
    }
    else {
      query.push_back({0, 0});
    }
  }  
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  for(auto [p, v] : query) {
    if(v == 0) {
      cout << st[1][2] << '\n';
    }
    else {
      int pos = lower_bound(s.begin(), s.end(), p) - s.begin() + 1;
      update(1, 1, (int) s.size(), pos, v);
    }
  }
}

