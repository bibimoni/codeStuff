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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<pair<string, int>> events(m);
  vector<int> preX(m, 0), preY(m, 0);
  vector<int> rot(m, 0);
  vector<int> coffX(m, 1), coffY(m, 1);
  auto ccw = [&] (int &x, int &y) -> void {
    int x_n = -y;
    int y_n = x;
    x = x_n;
    y = y_n;
  };
  auto cw = [&] (int &x, int &y) -> void {
    int x_n = y;
    int y_n = -x;
    x = x_n;
    y = y_n;
  };
  for(int i = 0; i < m; i++) {
    string t;
    cin >> t;
    int k = -1;
    if(t == "xflip" || t == "yflip") {
      cin >> k;
    }
    rot[i] = (i == 0 ? 0 : rot[i - 1]) + (t == "cw" || t == "ccw");
    preX[i] = (i == 0 ? 0 : preX[i - 1]) + (t == "xflip" ? 2 * k - 2 * (i == 0 ? 0 : preX[i - 1]) : 0);
    preY[i] = (i == 0 ? 0 : preY[i - 1]) + (t == "yflip" ? 2 * k - 2 * (i == 0 ? 0 : preY[i - 1]) : 0);
    coffX[i] = (i == 0 ? 1 : coffX[i - 1]);
    coffY[i] = (i == 0 ? 1 : coffY[i - 1]);
    if(t == "cw") {
      cw(preX[i], preY[i]);  
      cw(coffX[i], coffY[i]);
    }
    else if(t == "ccw") {
      ccw(preX[i], preY[i]);
      ccw(coffX[i], coffY[i]);
    }
    else if(t == "xflip") {
      coffX[i] *= -1;
    }
    else if(t == "yflip") {
      coffY[i] *= -1;
    }
    events[i] = {t, k};
  }
  while(q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    auto [u, v] = a[x];
    if(rot[y] & 1)
      swap(u, v);
    u = preX[y] + coffX[y] * u;
    v = preY[y] + coffY[y] * v;
    cout << u << ' ' << v << '\n';
  }
}


