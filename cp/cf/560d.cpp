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
#define sz(_x) (_x).size()
const int N = (int) 2e5 + 5, MOD = (int) 1e9 + 7;

bool cmpFn(int la, int ra, int lb, int rb, string &a, string &b) {
  for(int i = 0; i <= ra - la; i++) {
    if(a[la + i] != b[lb + i]) {
      return false;
    }
  }
  return true;
}

bool Try(int la, int ra, int lb, int rb, string &a, string &b) {
  // dbg(la, ra, lb, rb);
  if(cmpFn(la, ra, lb, rb, a, b)) {
    return true;
  }
  if((ra - la + 1) & 1) {  
    return false;
  }
  int mida = (la + ra) >> 1, midb = (lb + rb) >> 1;
  return ((Try(la, mida, lb, midb, a, b) && Try(mida + 1, ra, midb + 1, rb, a, b)
    || (Try(la, mida, midb + 1, rb, a, b) && Try(mida + 1, ra, lb, midb, a, b))));
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string a, b; 
  cin >> a >> b;
  int n = a.size();
  a = " " + a;
  b = " " + b;
  cout << (Try(1, n, 1, n, a, b) ? "YES\n" : "NO\n");
}

