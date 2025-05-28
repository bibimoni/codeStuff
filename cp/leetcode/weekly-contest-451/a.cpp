#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long minCuttingCost(int n, int m, int k) {
#define int int64_t
    if (n > m) {
      swap(n, m);
    }
    long long cost = (m > k ? int(k) * (m - k): 0);
    return cost;
  }
#ifdef int
#undef int
#endif
};

