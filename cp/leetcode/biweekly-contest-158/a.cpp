#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxSumDistinctTriplet(vector<int> &x, vector<int> &y) {
    int n = (int)x.size();
    const int mx = *max_element(x.begin(), x.end());
    vector<int> pp(mx + 1, -1);
    for (int i = 0; i < n; i++) {
      pp[x[i]] = max(pp[x[i]], y[i]);
    }
    vector<int> bruh;
    for (int i = 1; i <= mx; i++) {
      if (pp[i] != -1)
        bruh.push_back(pp[i]);
    }
    sort(bruh.begin(), bruh.end(), greater<int>());
    if (bruh.size() < 3) {
      return -1;
    }
    return bruh[0] + bruh[1] + bruh[2];
  }
};
