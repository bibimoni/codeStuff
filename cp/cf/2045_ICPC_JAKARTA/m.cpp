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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  int cnt_m = 0;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    for (char c : a[i]) {
      cnt_m += c != '.';
    }
  }
  map<pair<char, pair<int, int>>, pair<int, int>> mp;
  mp[{'/', {0, 1}}] = {-1, 0};
  mp[{'/', {1, 0}}] = {0, -1};
  mp[{'/', {-1, 0}}] = {0, 1};
  mp[{'/', {0, -1}}] = {1, 0};
  mp[{'\\', {0, 1}}] = {1, 0};
  mp[{'\\', {1, 0}}] = {0, 1};
  mp[{'\\', {0, -1}}] = {-1, 0};
  mp[{'\\', {-1, 0}}] = {0, -1};
  auto bfs = [&] (int rs, int cs, pair<int, int> off) -> bool {
    int cur_r = rs, cur_c = cs;
    set<pair<int, int>> st;
    while (true) {
      if (a[cur_r][cur_c] != '.') {
        st.insert({cur_r, cur_c});
        off = mp[{a[cur_r][cur_c], off}];
      }
      cur_r += off.first;
      cur_c += off.second;
      if (cur_r < 0 || cur_c < 0 || cur_r >= h || cur_c >= w) {
        break;
      }
    }
    return st.size() == cnt_m;
  };
  vector<string> ans;
  for (int i = 0; i < h; i++) {
    if (bfs(i, 0, {0, 1})) {
      ans.push_back("W" + to_string(i + 1));
    }
    if (bfs(i, w - 1, {0, -1})) {
      ans.push_back("E" + to_string(i + 1));
    }
  }
  for (int i = 0; i < w; i++) {
    if (bfs(0, i, {1, 0})) {
      ans.push_back("N" + to_string(i + 1));
    }
    if (bfs(h - 1, i, {-1, 0})) {
      ans.push_back("S" + to_string(i + 1));
    }
  }
  cout << ans.size() << '\n';
  for (const string p : ans) {
    cout << p << ' ';
  }

}

