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
  string s;
  cin >> s;
  int n = s.size();
  string t = "";
  for(char c : s) {
    if(t.empty() || c != t.back())
      t += c;
  }
  while(t.size() >= 4) {
    for(int i = 0; i < 2; i++)
      t.pop_back();
  }
  cout << t << '\n';
}

