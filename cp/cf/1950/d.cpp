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
  vector<int> nums;
  nums.push_back(100000);
  for(int i = 2; i < (1 << 5); i++) {
    int num = 0;
    for(int j = 5; j >= 0; j--) {
      num = num * 10 + ((i >> j) & 1);
    }
    nums.push_back(num);
  }
  sort(nums.begin(), nums.end(), greater<int>());
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 0; i < nums.size(); i++) {
      while(n % nums[i] == 0) {
        n /= nums[i];
      }
    }
    cout << (n == 1 ? "YES\n" : "NO\n");
  }
}

