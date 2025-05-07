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
const int N = (int) 1e6 + 5;
// Computing smallest prime factor as sieve in O(nloglogn)
// Largest prime factor can be computed by removing (a[j] == 0) condition
vector<int> spf(int n) {
  n++;
  vector<int> a(n);
  a[1] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i] == 0) {
      a[i]  = i;
      for (int j = 2 * i; j < n; j += i) {
        if (a[j] == 0) a[j] = i;
      }
    }
  }
  return a;
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  auto minPrime = spf(N);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) {
      cin >> i;
    }
    int prev = 1, ans = 0;
    for(int i : a) {
      int curr = i;
      while(curr > 1) {
        int p = minPrime[curr];
        while(curr % p == 0) {
          ans += (prev % p != 0);
          if(prev % p == 0)
            prev /= p;
          curr /= p;
        }
      }
      prev = i;
    }
    cout << ans << '\n';
  }
}

