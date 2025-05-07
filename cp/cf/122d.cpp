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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = " " + s;
  for(int i = 1; i <= n && k > 0; i++) {
		if(i + 2 <= n && (i & 1) && (s.substr(i, 3) == "447" || s.substr(i, 3) == "477")) {
			int cnt = ((s[i + 1] == '7') + k) % 2;
			s[i + 1] = (cnt == 1 ? '7' : '4');
			break;
  	}
  	if(i + 1 <= n && s.substr(i, 2) == "47") {
  		if(i & 1)
  			s[i + 1] = '4';
  		else
  			s[i] = '7';
  		k--;
  	}
  }
  cout << s.substr(1);
}

