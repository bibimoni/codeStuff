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
    string s; cin >> s;
    char r = s[0];
    int c = s[1] - '0';
    for(char row = 'a'; row <= 'h'; row++) {
      if(row == r) continue;
      cout << row << c << '\n';
    }
    for(int col = 1; col <= 8; col++) {
      if(col == c) continue;
      cout << r << col << '\n';
    }
  }
}


