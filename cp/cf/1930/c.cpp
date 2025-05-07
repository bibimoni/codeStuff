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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n + 1];
    map<int, int, greater<int>> f;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      f[a[i] + i]++;
    }
    for(auto [v, c] : f) {
      if(c > 1) 
        f[v - 1] += c - 1;
    }   
    vector<int> ans;
    auto it = f.begin();
    for(int i = 0; i < n; i++) {
      if(it == f.end())
        break;
      ans.push_back(it->first);
      it++;
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for(int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  } 
}


