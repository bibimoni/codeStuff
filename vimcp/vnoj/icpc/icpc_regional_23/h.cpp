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

string k = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const int BASE = 31, MOD = (int) 1e9 + 3;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> c(n + 100, vector<int> (10, 0));
    int curr = 0;
    for(char ch : s) {
      int val = 0;
      for(int i = 0; i < 64; i++) {
        if(ch == k[i]) {
          val = i;
          break;
        }
      }
      for(int j = 0; j < 6; j++) {
        c[curr][j] = val & 1;
        val >>= 1;
      }
      curr++;
    }
    string b = "";
    for(int i = 0; i < (int) s.size(); i++) {
      for(int j = 0; j < 6; j++) {
        b += (c[i][j] + '0');
      }
    }
    vector<vector<int>> a(n + 100, vector<int>(n + 100, 0));
    int hashRow[n + 100];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i * n + j < (int) b.size())
        a[i][j] = (b[i * n + j] - '0');
      }
    }
    for(int i = 0; i < n; i++) {
      int hashVal = 0;
      for(int j = 0; j < n; j++) {
        hashVal = (hashVal * BASE + a[i][j] + 1) % MOD;
      }
      hashRow[i] = hashVal;
    }
    bool ok = false;
    for(int j = 0; j < n; j++) {
      int i1 = -1, i2 = -1;
      if(ok) break;
      for(int i = 0; i < n; i++) {
        if(ok) break;
        if(!a[i][j]) {
          if(i1 < 0) i1 = i;
          else if(hashRow[i1] != hashRow[i]) {
            i2 = i;
            for(int j1 = 0; j1 < n; j1++) {
              if(a[i1][j1] != a[i2][j1]) {
                cout << "YES\n";
                cout << i1 + 1 << ' ' << j + 1 << ' ' << i2 + 1 << ' ' << j1 + 1 << '\n';
                ok = true;
                break;
              }
            }
          }
        }
      }
    }
    if(!ok) cout << "NO\n";   
  }
}

