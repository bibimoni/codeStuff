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
  int n, m, k;
  cin >> n >> m >> k;
  if(n > m) swap(n, m);
  int lcm = (n * m) / __gcd(n, m);
  int cntN = lcm / n - 1, cntM = lcm / m - 1;
  int cnt = k / (cntN + cntM) - (k % (cntM + cntN) == 0);
  int k_th = cnt * (cntN + cntM);
  int currN = lcm * cnt + n, currM = lcm * cnt + m;
  int curr;
  while(true) {
    curr = min(currN, currM);
    if(curr % n == 0 || curr % m == 0) {
      k_th++;
    }
    if(curr % n == 0 && curr % m == 0) {
      k_th--;
    }
    if(k_th == k)
      break;
    if(currN <= currM) {
      currN += n;
    }
    else {
      currM += m;
    }
  } 
  cout << curr;
}


