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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = " " + s;
    vector<int> preB(n + 1, 0), preA(n + 1, 0);
    for(int i = 1; i < s.size(); i++) {
      preB[i] = preB[i - 1] + (s[i] == 'B');
      preA[i] = preA[i - 1] + (s[i] == 'A');
    }
    if(preB[n] == k) {
      cout << "0\n"; continue;
    }
    cout << "1\n";
    int ans = 0, needed = k - preB[n];
    if(needed < 0) {
      needed = preA[n] + (preB[n] - k);
      for(int i = 1; i <= n; i++) {
        if(i + preA[n] - preA[i] == needed) {
          cout << i << " A\n";
          break;
        }
      }
    }
    else {
      needed = k;
      for(int i = 1; i <= n; i++) {
        //dbg(preB[n], preB[i], i);
        if(i + preB[n] - preB[i] == needed) {
          cout << i << " B\n";
          break;
        }
      }
    }
  }
}


