#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long maximumProduct(vector<int> &a, int m) {
    int n = int(a.size());
    const long long INF = 1e18;
    vector<long long> mndp(n, INF), mxdp(n, -INF);
    long long ans = -INF;
    for (int i = 0; i < n; i++) {
      mndp[i] = a[i];
      mxdp[i] = a[i];
      if (i > 0) {
        mxdp[i] = max(mxdp[i - 1], mxdp[i]);
        mndp[i] = min(mndp[i - 1], mndp[i]);
      }
      if (i - m + 1 >= 0) {
        long long mn = mndp[i - m + 1];
        long long mx = mxdp[i - m + 1];
        ans = max({ans, 1LL * mn * a[i], 1LL * mx * a[i]});
      }
    }
    assert(ans != -INF);
    return ans;
  }
};
