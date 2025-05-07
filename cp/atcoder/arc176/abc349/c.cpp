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
  string s, t;
  cin >> s >> t;
  string o = "";
  for(char &c : s) {
  	c = c - 'a' + 'A';
  	for(char b : t) {
  		if(c == b) {
  			o += c;
  			break;
  		}
  	}
  }
  //////////
  bool ok = false;
  int id = 0;
  for(int i = 0; i < o.size(); i++) {
  	if(o[i] == t[id]) {
  		id++;
  	}
  	if(t[id] == 'X' && id == 2) {
  		ok = true;
  		break;
  	}
  	if(id == 3) {
  		ok = true;
  		break;
  	}
  }
  cout << (ok ? "Yes\n" : "No\n");
}


