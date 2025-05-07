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
#define int int64_t

const vector<int> dir{-1, 0, 1, 0, -1};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  vector<pair<pair<int, int>, int>> a(k + 1);
  for (int i = 0; i < k; i++) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    a[i].first.first -= 1;
    a[i].first.second -= 1;
  }
  const int INF = int(1e9);
  a[k] = {{0, 0}, 0}; // the k + 1 point is the starting point
  vector<vector<vector<int>>> dist(k + 1, vector<vector<int>>(n, vector<int>(n, INF)));

  int idx = 0;
  for (auto [coords, _] : a) {
    auto [x, y] = coords;
    deque<pair<int, int>> dq;
    dist[idx][x][y] = 0;
    dq.push_front({x, y});
    vector<vector<int>> was(n, vector<int>(n, 0));
    while (dq.size()) {
      auto [ux, uy] = dq.front();
      dq.pop_front();
      if (was[ux][uy]) {
        continue;
      }
      was[ux][uy] = 1;
      for (int i = 0; i < 4; i++) {
        int vx = ux + dir[i];
        int vy = uy + dir[i + 1];
        if (vx < 0 || vy < 0 || vx >= n || vy >= n || g[vx][vy] == '#') {
          continue;
        }
        if (dist[idx][vx][vy] <= dist[idx][ux][uy] + (g[vx][vy] == '+')) {
          continue;
        }
        dist[idx][vx][vy] = dist[idx][ux][uy] + (g[vx][vy] == '+');
        if (g[vx][vy] == '+') {
          dq.push_back({vx, vy});
        } else {
          dq.push_front({vx, vy});
        }
      }
    }
    idx += 1;
  }
  auto to_str = [&] (int num) -> string {
    string ret = "";
    while (num) {
      ret += string(1, char(num % 2 + '0'));
      num /= 2;
    }
    while(ret.size() < k)
      ret += "0";
    reverse(ret.begin(), ret.end());
    return ret;
  };
  // k = 10;
  // dbg(to_str(0b001011), to_str((0b000001 - 1) & 0b001011))
  // 001011 -> 001010 -> 001010 -> 001001 -> 001000 -> 000011 -> 000010 -> 000001 -> 000000
  vector<vector<int>> dp_sub(k, vector<int>((int(1) << k), INF));
  for (int i = 0; i < k; i++) {
    dp_sub[i][int(1) << i] = dist[i][0][0];
  }
  for (int mask = 0; mask < (int(1) << k); mask++) {
    for (int j = 0; j < k; j++) {
      if ((mask >> j) & 1)
      for (int i = 0; i < k; i++) {
        if (((mask >> i) & 1) ^ 1) {
          int cur_x = a[i].first.first;
          int cur_y = a[i].first.second;
          dp_sub[i][mask | (int(1) << i)] = min(dp_sub[j][mask] + dist[j][cur_x][cur_y], dp_sub[i][mask | (int(1) << i)]);
        }
      }
    }
  }

  vector<int> dp_fuel(int(1) << k, INF);
  for (int mask = 0; mask < (int(1) << k); mask++) {
    int weight = 0;
    for (int i = 0; i < k; i++) {
      if ((mask >> i) & 1) {
        weight += a[i].second;
      }
    }
    if (weight <= m) {
      for (int i = 0; i < k; i++) {
        dp_fuel[mask] = min(dp_fuel[mask], dp_sub[i][mask] + dist[i][0][0]);
      }
    }
  }
  for (int mask = 0; mask < (int(1) << k); mask++) {
    for (int sub_mask = mask; sub_mask != 0; sub_mask = (sub_mask - 1) & mask) {
      dp_fuel[mask] = min(dp_fuel[mask], dp_fuel[mask ^ sub_mask] + dp_fuel[sub_mask]);
    }
  }
  cout << dp_fuel[(int(1) << k) - 1];
} 

