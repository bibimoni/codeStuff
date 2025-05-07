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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p;
  for(int i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      p.push_back(i % 26);
      while(n % i == 0) {
        n /= i;
      }
    }
  }
  if(n != 1)
    p.push_back(n % 26);
  sort(p.begin(), p.end());
  for(int i : p) {
    cout << char(i + 'A');
  }
}


