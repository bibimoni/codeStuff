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
const int INF = (int) 1e18;

bool isPrime(int need) {
  if(need == 0 || need == 1) return false;
    for(int i = 2; i * i <= need; i++) {
      if(need % i == 0) {
        return false;
      }
    }
    return true;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b; cin >> a >> b;
    int need = b - a;
    if(need == 0) {
      cout << "0\n";
      continue;
    }
    if(need == 2) {
      cout << "1\n";
      continue;
    }
    if(need == 1) {
      cout << "-1\n";
      continue;
    } 
    if(need % 2 == 0) {
      cout << "2\n";
      continue;
    }
    if(isPrime(need)) {
      cout << "1\n";
      continue;
    }
    if(isPrime(need - 2)) {
      cout << "2\n";
    }
    else {
      cout << "3\n";
    }
  }
}

