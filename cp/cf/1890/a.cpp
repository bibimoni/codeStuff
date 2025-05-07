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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    map<int, int> f; 
    int a[n]; for(int &i : a) cin >> i, f[i]++;
    bool check = true;
    vector<int> tmp;
    for(auto [k, v] : f) {
      tmp.push_back(v);
    }
    sort(all(tmp)); check = (tmp[0] + 1 == tmp[1] || tmp[0] == tmp[1]);
    cout << (f.size() == 1 || (check && f.size() == 2) ? "Yes\n" : "No\n");
  }
}


