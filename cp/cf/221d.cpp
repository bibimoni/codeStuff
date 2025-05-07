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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const int BLOCK_SIZE = sqrt(n);
  vector<int> ans(m);
  vector<array<int, 3>> queries(m);
  for(int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r, i};
  }
  //Mo's algorithm
  sort(queries.begin(), queries.end(), [&] (array<int, 3> i, array<int, 3> j) {
    return pair<int, int>({i[0] / BLOCK_SIZE, i[1]}) < pair<int, int>({j[0] / BLOCK_SIZE, j[1]});
  });
  vector<int> cnt(n + 1, 0);
  int currL = 1, currR = 0, ret = 0;
  auto add = [&] (int val) {
    if(cnt[val] == val) {
      ret--;
    }
    cnt[val]++;
    if(cnt[val] == val) {
      ret++;
    }
  };
  auto remove = [&] (int val) {
    if(cnt[val] == val) {
      ret--;
    }
    cnt[val]--;
    if(cnt[val] == val) {
      ret++;
    }
  };
  for(auto [l, r, id] : queries) {
    while(currL > l) {
      currL--;
      if(a[currL] <= n)
        add(a[currL]);
    }
    while(currR < r) {
      currR++;
      if(a[currR] <= n)
        add(a[currR]);
    }
    while(currL < l) {
      if(a[currL] <= n)
        remove(a[currL]);        
      currL++;
    }
    while(currR > r) {
      if(a[currR] <= n)
        remove(a[currR]);  
      currR--;
    }
    ans[id] = ret;
  }
  for(int i : ans) {
    cout << i << '\n';
  }
}

