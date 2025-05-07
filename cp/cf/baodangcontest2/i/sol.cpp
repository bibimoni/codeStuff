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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int cntB = 0, cntC = 0;
    for(char i : a) {
      if(i == 'C') cntB++;
    }
    for(char i : b) {
      if(i == 'B') cntC++;
    }
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    if(a.size() == 1 || (cntB <= cntC && b.size() != 1)) {
      cout << "BAO\n";
    }
    else {
      cout << "CHUNG\n";
    }
  }
}

