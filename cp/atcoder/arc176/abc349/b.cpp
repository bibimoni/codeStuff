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
  string s;
  cin >> s;
  int n = s.size();
  map<char, int> cnt;
  for(char c : s) {
  	cnt[c]++;
  }
  bool ok = true;
  for(int i = 1; i <= n; i++) {
  	int count = 0;
  	for(char c = 'a'; c <= 'z'; c++) {
  		count += cnt[c] == i;
  	}
  	if(count != 0 && count != 2) 
  		ok = false;
  }
  cout << (ok ? "Yes\n" : "No\n");
}


