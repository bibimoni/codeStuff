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

const int N = 15;
int a[N], n, m;
vector<int> b;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  vector<vector<int>> li;  
  auto dfs = [&] (auto &&self, int i, vector<int> &cur) {
    if (i == n) {
      if (cur.size()) {
        li.push_back(cur);
      }
      return;
    }
    cur.push_back(a[i]);
    self(self, i + 1, cur);
    cur.pop_back();
    self(self, i + 1, cur);
  };
  vector<int> tmp;
  dfs(dfs, 0, tmp);
  sort(li.begin(), li.end());
  li.erase(unique(li.begin(), li.end()), li.end());
  int k = 0;
  bool found = false;
  for (auto p : li) {
    k += 1;
    // dbg(k, p);
    if (p == b) {
      found = true;
      break;
    }
  }
  cout << (!found ? -1 : k);
}

