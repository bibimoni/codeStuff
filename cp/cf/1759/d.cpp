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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    int cnt = 2;
    auto get25 = [&] (int num) {
      pair<int, int> ans({0, 0});
      while(num > 1 && num % 2 == 0) {
        num /= 2;
        ans.first++;
      }
      while(num > 1 && num % 3 == 0) {
        num /= 3;
      }
      while(num > 1 && num % 5 == 0) {
        num /= 5;
        ans.second++;
      }
      return ans;
    };
    auto [cnt2, cnt5] = get25(n);
    int k = 1;
    if(cnt2 < cnt5) {
      while(cnt2 < cnt5 && k * 2 <= m) {
        k *= 2;
        n *= 2;
        cnt2++;
      }
    }
    if(cnt5 < cnt2) {
      while(cnt2 > cnt5 && k * 5 <= m) {
        k *= 5;
        n *= 5;
        cnt5++;
      }
    }
    while(k * 10 <= m) {
      k *= 10;
      n *= 10;
    }   
    for(int i = 9; i >= 2; i--) {
      if(k * i <= m) {
        n *= i;
        break;
      }
    }
    cout << n << '\n';
  }
}


