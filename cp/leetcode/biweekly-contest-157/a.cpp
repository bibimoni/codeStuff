#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long sumOfLargestPrimes(string s) {
    int n = s.size();
    vector<long long> primes;
    auto toNum = [&](string t) -> long long {
      long long ret = 0;
      for (int i = 0; i < t.size(); i++) {
        ret = ret * 10 + t[i] - '0';
      }
      return ret;
    };
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        long long num = toNum(s.substr(i, j - i + 1));
        bool ok = num > 1;
        for (long long x = 2; x * x <= num; x++) {
          ok &= num % x != 0;
        }
        if (ok) {
          primes.push_back(num);
        }
      }
    }
    sort(primes.begin(), primes.end(), greater<long long>());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    long long sum = 0;
    for (int i = 0; i < min(3, (int)primes.size()); i++) {
      sum += primes[i];
    }
    return sum;
  }
};
