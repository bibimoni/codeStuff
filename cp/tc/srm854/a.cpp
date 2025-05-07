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

string check(int n, vector<int> bags, int e) {
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += bags[i];
  }
  int rem = sum - e;
  if(rem % n != 0 || rem < 0 && rem < n) {
    return "impossible";
  }
  int one = rem / n;
  bool ok = true;
  for(int i = 0; i < n; i++) {
    if(one < bags[i])
      ok = false;
  }
  return (ok ? "possible" : "impossible");
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);

}


