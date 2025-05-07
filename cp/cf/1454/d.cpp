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
    map<int, int> cnt;
    for(int i = 2; i * i <= n; i++) {
      if(n % i == 0) {
        int c = 0;
        while(n % i == 0) {
          c++;
          n /= i;
        }
        cnt[i] += c;
      }
    }  
    if(n != 1) {
      cnt[n]++;
    }
    vector<pair<int, int>> a;
    for(auto [p, v] :cnt) {
      a.push_back({p, v});
    }
    sort(a.begin(), a.end(), [&] (pair<int, int> i, pair<int, int> j) {
      return i.second > j.second;
    });
    vector<int> ans(a[0].second, 1);
    for(int i = 0; i < a[0].second; i++) {
      ans[i] *= a[0].first;
    }
    for(int i = 1; i < a.size(); i++) {
      for(int j = 0; j < a[i].second; j++) {
        ans[ans.size() - 1] *= a[i].first;
      }
    }
    cout << ans.size() << '\n';
    for(int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}


