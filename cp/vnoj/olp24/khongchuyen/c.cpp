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

// Get primes not greater than n in O(nloglogn)
vector<int> getprimes(int n) {
  vector<int> p;
  vector<bool> is(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    if (is[i]) {
      p.push_back(i);
      for (int j = 2 * i; j <= n; j += i) is[j] = 0;
    }
  }
  return p;
}

int pow_mod(int x, int y) {
  int ret = 1, cur = x;
  const int INF = 2e18;
  while (y) {
    if (y & 1) {
      if (ret > INF / cur) {
        return -1;
      }
      ret *= cur;
    }
    if (cur > INF / cur) {
      return -1;
    }
    cur *= cur;
    y /= 2;
  }
  return ret;
}

int mulc(int x, int y) {
  const int INF = 2e18;
  if (x == -1 || y == -1) {
    return -1;
  }
  if (x > INF/ y) {
    return -1;
  }
  return x * y;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  const int N = 1e6 + 5, M = 2705;
  vector<int> primes = getprimes(N);
  vector<array<int, 3>> triplets;
  for (int i = 1; i < M; i++) {
    for (int j = 1; j < M; j++) {
      if (k % ((i + 1) * (j + 1)) == 0 && (k / ((i + 1) * (j + 1))) > 1) {
        triplets.push_back({i, j, k / ((i + 1) * (j + 1)) - 1});
      }
    }
  }
  dbg(triplets);
  int m = -1;
  for (int i = primes.size() - 1; i - 2 >= 0; i--) {
    int p1 = primes[i];
    int p2 = primes[i - 1];
    int p3 = primes[i - 2];
    if (p1 * p2 * p3 <= n) {
      for (int j = triplets.size() - 1; j >= 0; j--) {
        int pn1 = pow_mod(p1, triplets[j][0]);
        int pn2 = pow_mod(p2, triplets[j][1]);
        int pn3 = pow_mod(p3, triplets[j][2]);
        if (pn1 == -1 || pn2 == -1 || pn3 == -1) {
          continue;
        }
        int ret = mulc(pn1, mulc(pn2, pn3));
        if (ret == -1) {
          continue;
        }
        if (ret <= n) {
          m = max(m, pn1 * pn2 * pn3);
        }
      }
    }
  }
  assert(m != -1);
  cout << m;
}


