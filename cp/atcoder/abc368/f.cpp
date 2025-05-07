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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = *max_element(a.begin(), a.end());
  auto find_div = [&] (int num) -> vector<int> {
    vector<int> ret;
    for (int i = 1; i * i <= num; i++) {
      if (num % i == 0) {
        ret.push_back(i);
        if (i * i != num && i != 1) {
          ret.push_back(num / i);
        }
      }
    }
    return ret;
  };
  vector<int> nums(mx + 1, 0);
  for (int i = 1; i <= n; i++) {
    auto divs = find_div(i);
    int mn = 0;
    for (auto d : divs) {
      mn = max(mn, nums[i]);
    }
    if (mn == 1e9) {
      nums[i] = 0;
    } else {
      nums[i] = mn + 1;
    }
  }
  dbg(nums);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    tot += nums[a[i]];
  }
  dbg(tot);
  cout << (tot % 2 ? "Anna\n" : "Bruno\n");
}


