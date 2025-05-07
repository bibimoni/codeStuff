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
#define int long long

int ask(int x, int y) {
  cout << "? " << x << ' ' << y << '\n';
  cout.flush();
  int ans;
  cin >> ans;
  cout.flush();
  return ans;
}

pair<int, int> intersect(int a, int b, int c, int at, int bt, int ct) {
  if((bt * a - at * b == 0) || (bt * a - at * b) == 0)
    return {-1, -1};
  double xi = (ct * b - bt * c) / ((double) bt * a - at * b);
  double yi = (at * c - ct * a) / ((double) bt * a - at * b);
  if(xi != (int) xi || yi != (int) yi)
    return {-1, -1};
  return {(int) xi, (int) yi};
}

array<int, 3> convert(pair<int, int> a, pair<int, int> b) {
  return {(a.second - b.second), -(a.first - b.first), (a.first * b.second - b.first * a.second)};
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  cout.flush();
  while(tt--) {
    int n, m;
    cin >> n >> m;
    cout.flush();
    vector<array<int, 3>> l;
    pair<int, int> ans = {-1, -1};
    //(1, 1)
    {
      int ret = ask(1, 1);
      if(ret == 0) {
        ans = {1, 1};
      }
      pair<int, int> a(1, ret + 1), b(ret + 1, 1); 
      l.push_back(convert(a, b));
    }
    if(ans != pair<int, int>(-1, -1)) {
      cout << "! " << ans.first << ' ' << ans.second << '\n';
      cout.flush();
      continue;
    }
    pair<int, int> corner1(1, 1), corner2(n, 1), corner3(1, m);
    l.push_back(convert(corner1, corner2));
    l.push_back(convert(corner1, corner3));
    pair<int, int> intern1 = intersect(l[0][0], l[0][1], l[0][2], l[1][0], l[1][1], l[1][2]);
    pair<int, int> inter1m = intersect(l[0][0], l[0][1], l[0][2], l[2][0], l[2][1], l[2][2]);    
    if(intern1 == inter1m) {
      cout << "! " << intern1.first << ' ' << intern1.second << '\n';
      cout.flush();
      continue;
    }
    int ret = ask(intern1.first, intern1.second);
    ans = {intern1.first - ret / 2, intern1.second + ret / 2};
    ret = ask(ans.first, ans.second);
    if(ret == 0) {
      cout << "! " << ans.first << ' ' << ans.second << '\n';
    }
    else {
      ans = {inter1m.first + ret / 2, inter1m.second - ret / 2};
      cout << "! " << ans.first << ' ' << ans.second << '\n';      
    }
    cout.flush();
  }
}


