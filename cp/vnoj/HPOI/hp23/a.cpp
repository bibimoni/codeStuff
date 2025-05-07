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
  int num; cin >> num;
  map<int, int> cnt;
  for(int i = 2; i * i <= num; i++) {
    while(num % i == 0) {
      num /= i;
      cnt[i]++;
    }
  }
  if(num != 1) cnt[num]++;
  int ans = 1;
  for(auto [_, v] : cnt) {
    ans *= (v + 1);
  }
  cout << ans << '\n';
}

