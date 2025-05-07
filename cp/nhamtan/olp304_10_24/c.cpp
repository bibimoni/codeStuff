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
  int X = sqrt(1e9) + 5;
  map<int, int> cnt;
  vector<int> nums;
  nums.push_back(1);
  cnt[1] = 2;
  for(int i = 2; i <= X; i++) {
    int curr = i, pwr = 1;
    while(curr * curr < 1e9) {
      curr *= i;
    // dbg(curr);
      pwr++;
      nums.push_back(curr);
      cnt[curr] = pwr;
    }
  }
  sort(nums.begin(), nums.end());
  auto binSearch = [&] (int val) {
    int l = 0, r = nums.size() - 1, ret;
    while(l <= r) {
      int mid = (l + r);
      if(val < nums[mid]) {
        r = mid - 1;
      }
      else {
        l = mid + 1;
        ret = mid;
      }
    }
    return nums[ret];
  };
  // dbg(nums);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = 0;
    while(n > 0) {
      int get =  binSearch(n);
      dbg(get);
      ans += cnt[get];
      n -= get;
    }
    cout << ans << '\n';
  }
}


