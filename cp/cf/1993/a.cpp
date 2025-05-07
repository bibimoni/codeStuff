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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntA = count(s.begin(), s.end(), 'A');
    int cntB = count(s.begin(), s.end(), 'B');
    int cntC = count(s.begin(), s.end(), 'C');
    int cntD = count(s.begin(), s.end(), 'D');
    cntA = min(n, cntA);
    cntB = min(n, cntB);
    cntC = min(n, cntC);
    cntD = min(n, cntD);
    cout << cntA + cntB + cntC + cntD << '\n';
  }
}


