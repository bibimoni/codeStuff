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
    int n, x;
    cin >> n >> x;
    auto getEvenDivs = [&] (int t) -> vector<int> {
      vector<int> ret;
      for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
          if (i % 2 == 0) {
            ret.push_back(i);
          }
          if ((t / i) % 2 == 0) {
            ret.push_back(t / i);
          }
        }
      }
      for (auto& i : ret) {
        i = (i + 2) / 2;
      }
      return ret;
    };
    set<int> curr;
    auto p1 = getEvenDivs(n - x);
    auto p2 = getEvenDivs(n + x - 2);
    curr.insert(p1.begin(), p1.end());
    curr.insert(p2.begin(), p2.end());
    int ans = 0;
    for (int num : curr) {
      ans += (num >= x);
    }
    cout << ans << '\n';
  }
}


