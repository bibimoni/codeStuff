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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  auto num_divs = [&] (int num) -> set<int> {
    set<int> ret;
    for (int i = 1; i * i <= num; i++) {
      if (num % i == 0) {
        ret.insert(i);
        if (i * i != num) {
          ret.insert(num / i);
        }
      }
    }
    return ret;
  };

  auto lcm = [&] (int x, int y) -> int {
    return x / gcd(x, y) * y;
  };

  set<int> ans;
  int lcm_ab = lcm(a, b), 
    lcm_ac = lcm(a, c), 
    lcm_bc = lcm(b, c);

  if (n % lcm_ab == 0) {  
    auto p = num_divs(n / lcm_ab);
    ans.insert(p.begin(), p.end());
  }
  if (n % lcm_ac == 0) {
    auto p = num_divs(n / lcm_ac);
    ans.insert(p.begin(), p.end());
  }
  if (n % lcm_bc == 0) {
    auto p = num_divs(n / lcm_bc);
    ans.insert(p.begin(), p.end());  
  }
  
  cout << ans.size() << '\n';
}


