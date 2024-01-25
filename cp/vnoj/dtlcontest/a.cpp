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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    if(n == 1 || n == 0 || n == -1) {
      cout << "Piccolo\n";
      continue;
    }
    bool check = true, neg = (n < 0);
    if(n < 0) n = -n;
    map<int, int> fac;
    for(int i = 2; i * i <= n; i++) {
      while(n % i == 0) {
        fac[i]++;
        n /= i;
      }
    }
    if(n != 1) fac[n]++;
    //dbg(fac);
    if(fac.size() >= 2) {
      cout << "Majin Buu\n";
      continue;
    }
    int prime, cnt;
    for(auto [e, i] : fac) {
      prime = e, cnt = i;
    }
    dbg(prime, cnt);
    if(!neg) {
      if(cnt >= 2) cout << "Piccolo\n";
      else cout << "Majin Buu\n";
    }
    else {
      bool ok = false;
      while(cnt % 2 == 0 && cnt / 2 >= 2) {
        cnt /= 2;
        if(cnt & 1 && cnt >= 2) ok = true;
      }
      ok = (cnt & 1 && cnt >= 2);
      dbg(cnt, ok);
      if(ok) cout << "Piccolo\n";
      else {
        cout << "Majin Buu\n";
      }
    }
  }
}

