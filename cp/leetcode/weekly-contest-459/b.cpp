#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long maxTotalValue(vector<int> &nums, int k) {
    int curmx = nums[0], curmn = nums[0];
    int best = 0;
    for (int x : nums) {
      curmx = max(curmx, x);
      curmn = min(curmn, x);
      best = max({best, abs(x - curmx), abs(x - curmn)});
    }
    return best * k;
  }
};
