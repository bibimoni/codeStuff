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
    int a[n];
    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]]++;
    }
    int mex = 0;
    while(pos[mex] != 0) {
      mex++;
    }
    set<int> s;
    int r = -1;
    for(int i = 0; i < n; i++) {
      if(a[i] < mex) {
        s.insert(a[i]);
      }
      if(r == -1 && s.size() == mex) {
        r = i;
        s.clear();
      }
    }
    if(s.size() == mex) {
      cout << "2\n";
      cout << 1 << ' ' << r + 1 << '\n';
      cout << r + 2 << ' ' << n << '\n';
    }
    else {
      cout << "-1\n";
    }
  }
}


