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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> option = {n - 2 + m - 1, m - 2 + n - 1};
    bool check = false;
    for(int i = 0; i < 2; i++) {
      if((k - option[i]) % 4 == (i == 1 ? 1 : 3)) {
        check = true;
        cout << "YES\n";
        if(i == 0) {
          for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m - 1; j++) cout << "R ";
            cout << '\n';
          }
          for(int i = 0; i < m - 1; i++) cout << ((n - 1 + (i & 1)) % 2 == 0 ? "R " : "B ");
          cout << '\n'; 
          for(int i = 0; i < n - 1; i++) {
            if(i == 0) for(int j = 0; j < m; j++) cout << "B ";
            else for(int j = 0; j < m; j++) cout << (i & 1 ? "B " : "R ");
            cout << '\n';
          }
        }
        if(i == 1) {
          for(int i = 0; i < m - 1; i++) cout << (!(i & 1) ? "R " : "B ");
          cout << '\n';
          for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m - 1; j++) cout << "R ";
            cout << '\n';
          } 
          bool state = m & 1;
          for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m - 1; j++) cout << "B ";
            cout << (state ? "R " : "B "); state = !state;
            cout << '\n';
          }
        }
        break;
      }
    }
    if(!check) {
      cout << "NO\n";
    }
  }
}


