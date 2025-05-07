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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  sort(f.begin(), f.end());
  vector<pair<int, int>> s(m);
  for(int i = 0; i < m; i++) {
    cin >> s[i].first;
    s[i].second = i;
  }
  sort(s.begin(), s.end(), greater<pair<int, int>>());
  auto merge = [&] (vector<int> & in) -> vector<int> {
    vector<int> ret;
    reverse(in.begin(), in.end());
    int j = 0;
    for(int i = 0; i < n; i++) {
      while(j < in.size() && in[j] <= f[i]) {
        ret.push_back(in[j++]);
      }
      if(j >= in.size() || f[i] < in[j]) {
        ret.push_back(f[i]);
      }
    }
    while(j < in.size()) {
      ret.push_back(in[j++]);
    }
    return ret;
  };
  //101001
  auto can = [&] (int x) -> bool {
    vector<int> make;
    for(int i = 0; i < x; i++) {
      make.push_back(s[i].first);
    }
    auto combine = merge(make);
    int day = 0;
    for(int i = 0; i < combine.size(); i++) {
      if(combine[i] < day) {
        return false;
      }
      day += ((i + 1) % k == 0);
    }
    return true;
  };
  int l = 0, r = m, ret = -1;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(can(mid)) {
      ret = mid;
      l = mid + 1;
    } 
    else {
      r = mid - 1;
    }
  } 
  cout << ret << '\n';
  if(ret != -1) {
    for(int i = 0; i < ret; i++) {
      cout << s[i].second + 1 << ' ';
    }
  }
}

