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
#define all(_x) (_x).begin(), (_x).end()

class dsu {
  vector<int> parent, size;

public:
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
  }
 
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
 
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a > b)
      swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    dsu dsu(26);
    vector<vector<int>> ids(26);
    for(char c = 'a'; c <= 'z'; c++) {
      for(int i = 0; i < n; i++) {
        if(s[i] == c) {
          ids[c - 'a'].push_back(i);
        }
      }
    }
    cin >> s;
    int id = 0;
    while(k > 0 && id < n) {
      char si = s[id];
      for(int i = id; i < n; i++) {
        if(dsu.find(s[i] - 'a') <= k) {
          si = max(si, (char) (dsu.find(s[i] - 'a') + 'a'));
          id = i + 1;
        }
        else {
          break;
        }
      }
      int need = min((int) si - 'a', k);
      k -= need;
      char final = si - need;
      for(int j = 0; j < need; j++) {
        dsu.unite(final - 'a', si - j - 'a');
      }
    } 
    string ans = s;
    for(int i = 0; i < n; i++) {
      ans[i] = char(dsu.find(s[i] - 'a') + 'a');
    }
    cout << ans << '\n';
  }
}

