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

const int N = (int) 2e5 + 5, INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    bool check = true; 
    queue<int> pos[26];
    for(int i = 0; i < n; i++) pos[s[i] - 'a'].push(i);
    for(int i = 0; i < m; i++) {
      int c = t[i] - 'a';
      if(pos[c].size() == 0) {check = false; break;}
      for(int j = 0; j < c; j++) {
        while(pos[j].size() && pos[j].front() < pos[c].front()) pos[j].pop();
      }
      pos[c].pop();
    }
    cout << (check ? "YES\n" : "NO\n");
  }
}


