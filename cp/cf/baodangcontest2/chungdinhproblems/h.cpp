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
  int tt;
  cin >> tt;
  while(tt--) {
    int p, q; 
    cin >> p >> q;
    int pow2[21], pow3[21];
    pow2[0] = pow3[0] = 1;
    for(int i = 1; i <= 20; i++) {
      pow2[i] = pow2[i - 1] * 2ll;
      pow3[i] = pow3[i - 1] * 3ll;
    }
    auto solve = [&] () {
      vector<int> nums(21);
      iota(nums.begin(), nums.end(), 0);
      for(int cnt3x : nums) 
      for(int cnt2x : nums)
      for(int cnt3y : nums)
      for(int cnt2y : nums) {
        int same = min(cnt3x, cnt3y) + min(cnt2x, cnt2y);
        int diff2 = max(cnt2x, cnt2y) - min(cnt2x, cnt2y);
        int diff3 = max(cnt3x, cnt3y) - min(cnt3x, cnt3y);
        if(same + diff2 + diff3 > 20 || cnt3x + cnt3y + cnt2x + cnt2y == 0 || same == 0)
          continue;
        int x = pow3[cnt3x] * pow2[cnt2x];
        int y = pow3[cnt3y] * pow2[cnt2y];
        if(abs(x - y) * q - p * x * y == 0) {
          dbg(cnt3x, cnt2x, cnt3y, cnt2y);
          return true;
        }
      }
      return false;
    };
    if(solve()) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}

