#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minSwaps(vector<int> &a) {
    int n = a.size();
    vector<int> b(a.begin(), a.end());
    auto sum = [&] (int num) {
      int ret =0;
      while (num) {
        ret += num % 10;
        num /= 10;
      }
      return ret;
    };
    sort(b.begin(), b.end(), [&] (int i, int j) {
      if (sum(i) != sum(j)) {
        return sum(i) < sum(j);
        } else {
        return i < j;
        }
    })    

    map<int, int> pos;
    for (int i = 0; i < n; i++) {
      pos[a[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] != a[i]) {
        int id = pos[b[i]];
        swap(a[i], a[id]);
        pos[a[i]] = i;
        pos[a[id]] = id;
        ans += 1;
      }
    }
    return ans;
  }
};
