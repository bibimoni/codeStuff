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
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int app = 0, ora = 0;
    int a[2 * n - 1], o[2 * n - 1];
    vector<array<int, 3>> t1, t2;
    for(int i = 0; i < 2 * n - 1; i++) {
      cin >> a[i] >> o[i];
      app += a[i]; ora += o[i];
      t1.push_back({a[i], o[i], i});
      t2.push_back({a[i], o[i], i});      
    }
    sort(all(t1), greater<array<int, 3>>()); 
    sort(all(t2), [] (array<int, 3> b, array<int, 3> c) {
      return b[1] > c[1];
    });
    bool vis[2 * n - 1];
    memset(vis, false, sizeof vis); bool f = true;
    int cnt = 1, i = 0, j = 0, ca = 0, co = 0;
    vector<int> res;
    while(cnt <= n) {
      if(f) {
        while(i < 2 * n - 1 && vis[t1[i][2]]) i++;
        if(!vis[t1[i][2]]) {
          ca += t1[i][0];
          co += t1[i][1];
          vis[t1[i][2]] = true;
        }
        res.push_back(t1[i][2]);
        dbg(t1[i][2]);
        i++;
      }
      else {
        while(j < 2 * n - 1 && vis[t2[j][2]]) j++;
        if(!vis[t2[j][2]]) {
          co += t2[j][1];
          ca += t2[j][0];
          vis[t2[j][2]] = true;
        }
        res.push_back(t2[j][2]);
        dbg(t2[j][2]);
        j++;
      }
      cnt++;
      f = !f;
    }
    dbg(ca, co);
    if(ca < app / 2 || co < ora / 2) {
      cout << "NO\n";
      cout << '\n';
    }
    else {
      cout << "YES\n";
      for(auto e : res) cout << e + 1 << ' ';
      cout << '\n';
    }
  }
}


