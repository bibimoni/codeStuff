/**
 * File              : vpc23_g.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 04.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}
bool cmp(pair<int, int> &a, pair<int, int> &b) {
  return a.first > b.first;
}

vector<pair<int, int>> compute(vector<pair<int, int>> a) {
  vector<pair<int, int>> res;
  while(sz(a) > 0) {
    pair<int, int> curr = a.back(); a.pop_back();
    if(sz(a) == 0) {
      res.push_back({curr.first, curr.second});
      break;
    }
    pair<int, int> next = a.back();
    if(curr.second >= next.first) {
      curr.second = max(curr.second, next.second);
      a.pop_back();
      a.push_back(curr);
    }
    else {
      res.push_back({curr.first, curr.second});
    }
  }
  return res;
}

signed main() {
  TLE;
  int n, maxX, maxY; cin >> n >> maxX >> maxY;
  vector<pair<int, int>> rows, cols;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int x, y, w; cin >> x >> y >> w;
    rows.push_back({max(1ll, x - w), min(x + w, maxX)});
    cols.push_back({max(1ll, y - w), min(y + w, maxY)});
  }
  sort(all(rows), cmp); sort(all(cols), cmp);
  rows = compute(rows); cols = compute(cols);
  int rowWidth = 0, colWidth = 0;
  for(auto p : rows) {
    ans += (p.second - p.first + 1) * maxY;
    rowWidth += (p.second - p.first + 1);
  }
    //cout << endl;
  for(auto p : cols) {
    ans += (p.second - p.first + 1) * maxX;
    colWidth += (p.second - p.first + 1);
  }
  ans -= rowWidth * colWidth;
  cout << ans;
}

