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
  int s1 = 0;
  for(int i = 0; i < 9; i++) {
    int x; 
    cin >> x;
    s1 += x;
  }
  int s2 = 0;
  for(int i = 0; i < 8; i++) {
    int x;
    cin >> x;
    s2 += x;
  }
  cout << (s1 - s2 + 1);
  
}


