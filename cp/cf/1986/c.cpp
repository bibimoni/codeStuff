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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> idx(m + 1);
    for (int i = 1; i <= m; i++) {
      cin >> idx[i];
    }     
    string c;
    cin >> c;
    s = "#" + s;
    c = "#" + c;
    sort(idx.begin() + 1, idx.end());
    sort(c.begin() + 1, c.end());
    string newC = c;
    vector<int> mark(m + 1, 0);
    for (int i = 1; i <= m; i++) {
      while (i + 1 <= m && idx[i + 1] == idx[i]) {
        mark[i] = 1;
        i++;
      }
    }
    int id = m;
    for (int i = 1; i <= m; i++) {
      if(mark[i]) {
        newC[i] = c[id--];
      }
    }
    id = 1;
    for (int i = 1; i <= m; i++) {
      if(!mark[i]) {
        newC[i] = c[id++];
      }
    }
    for (int i = 1; i <= m; i++) {
      s[idx[i]] = newC[i];
    }
    for (int i = 1; i <= n; i++) {
      cout << s[i];
    }
    cout << '\n';
  }  
}


