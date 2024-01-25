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
const int INF = (int) 1e9;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
     cin >> a[i];
    }
    vector<int> t1, t2;
    int cnt = 0;
    t1.push_back(INF); t2.push_back(INF);
    for(int i = 0; i < n; i++) {
      if(t1.back() >= a[i]) t1.push_back(a[i]);
      else if(t2.back() >= a[i]) t2.push_back(a[i]);
      else {
        if(a[i] > t2.back()) {
          t1.push_back(t2.back());
          t2.pop_back();
          t2.push_back(a[i]);
        }
        else {
          t1.push_back(a[i]);
        }
        cnt++;
      }
    }    
    cout << cnt << '\n';
  }
}