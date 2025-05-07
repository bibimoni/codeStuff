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
  freopen("MATMA.INP", "r", stdin);
  freopen("MATMA.OUT", "w", stdout);
  string s; 
  cin >> s;
  int n = s.size();
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  dbg(s);
  int sum = 0;
  for(char i : s) {
    sum += (i - '0'); 
  }
  if(sum % 3 != 0 || s[s.size() - 1] != '0') {
    cout << "-1\n";
  }
  else {
    for(char i : s) {
      cout << i;
    }
  }
}


