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

bool isVowel(char i) {
  return i == 'a' || i == 'u' || i == 'i' || i == 'e' || i == 'o';
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("CAU4.INP", "r", stdin);
  freopen("CAU4.OUT", "w", stdout);
  string s; cin >> s;
  int n = s.size();
  vector<int> sufVo(n), sufCo(n);
  sufVo[n - 1] = (int) isVowel(s[n - 1]);
  sufCo[n - 1] = !sufVo[n - 1];
  for(int i = n - 2; i >= 0; i--) {
    sufVo[i] = sufVo[i + 1] + (int) isVowel(s[i]);
    sufCo[i] = sufCo[i + 1] + (int) !isVowel(s[i]);
  }
  int ans = 0;
  for(int i = 0; i < n - 1; i++) {
    if(isVowel(s[i])) 
      ans += sufCo[i + 1];
    else 
      ans += sufVo[i + 1];
  }
  cout << ans;
}


