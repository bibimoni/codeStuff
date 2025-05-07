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
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    vector<int> ord;
    for(auto c : s) {
      if(c == 'L') 
        ord.push_back(a[l++]);
      if(c == 'R')
        ord.push_back(a[r--]);
    }
    reverse(ord.begin(), ord.end());
    int prod = ord[0] % m;
    vector<int> ans({prod});
    for(int i = 1; i < ord.size(); i++) {
      (prod *= ord[i]) %= m;
      ans.push_back(prod);
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans) 
      cout << i << ' ';
    cout << '\n';
  }
}