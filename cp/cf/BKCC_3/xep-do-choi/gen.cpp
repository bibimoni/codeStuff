// gen_toys_corner.cpp
// Compile:
//   g++ -std=c++17 gen_toys_corner.cpp -O2 -o gen
// Example:
//   ./gen -T=20 -N=200 -MAX_A=1000000000 -seed=123
//
// Output format:
//   T
//   n k
//   a1 a2 ... an
//   ...

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// helpers to cap values within [0, MAX_A]
static inline ll cap_ll(ll x, ll MX) {
  if (x < 0)
    return 0;
  if (x > MX)
    return MX;
  return x;
}

// pattern generators
void gen_all_zeros(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  a.assign(n, 0);
}

void gen_single_large(vector<ll> &a, int n, int /*k*/, int MAX_A, bool first) {
  a.assign(n, 0);
  ll big = MAX_A;
  if (big == 0)
    big = 1;
  if (big > (ll)1e9)
    big = (ll)1e9;
  if (first)
    a[0] = big;
  else
    a[n - 1] = big;
}

void gen_all_equal(vector<ll> &a, int n, int /*k*/, int MAX_A, int val) {
  a.assign(n, cap_ll(val, MAX_A));
}

void gen_many_ones_some_large(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  a.assign(n, 1);
  int big_count = min(n, max(1, n / 10));
  for (int i = 0; i < big_count; ++i) {
    a[i] = cap_ll(MAX_A, MAX_A);
  }
}

void gen_alternating_big_zero(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  a.assign(n, 0);
  ll big = max(1, MAX_A);
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0)
      a[i] = cap_ll(big, MAX_A);
  }
}

void gen_increasing_seq(vector<ll> &a, int n, int /*int k*/, int MAX_A) {
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    // spread values from 0..MAX_A
    a[i] = (ll)((long double)MAX_A * i / max(1, n - 1));
  }
}

void gen_decreasing_seq(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  int tmp;
  gen_increasing_seq(a, n, tmp, MAX_A);
  reverse(a.begin(), a.end());
}

void gen_arith_prog(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  a.resize(n);
  int d = max(1, MAX_A / max(1, n));
  for (int i = 0; i < n; ++i)
    a[i] = cap_ll((ll)i * d, MAX_A);
}

void gen_powers_of_two(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  a.resize(n);
  ll v = 1;
  for (int i = 0; i < n; ++i) {
    a[i] = cap_ll(v, MAX_A);
    v = min<ll>(v * 2, MAX_A);
  }
}

void gen_fibonacci_like(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  a.assign(n, 0);
  if (n >= 1)
    a[0] = 1;
  if (n >= 2)
    a[1] = 1;
  for (int i = 2; i < n; ++i) {
    a[i] = cap_ll(a[i - 1] + a[i - 2], MAX_A);
  }
}

void gen_random_uniform(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  a.resize(n);
  for (int i = 0; i < n; ++i)
    a[i] = rnd.next(0, MAX_A);
}

void gen_heavy_tail(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  // Zipf-like: a_i ~ MAX_A / i
  a.resize(n);
  for (int i = 1; i <= n; ++i) {
    a[i - 1] = cap_ll(MAX_A / i, MAX_A);
  }
  // shuffle a bit
  for (int i = 0; i < n / 3; ++i) {
    int x = rnd.next(0, n - 1);
    int y = rnd.next(0, n - 1);
    swap(a[x], a[y]);
  }
}

void gen_border_sum_minus_one(vector<ll> &a, int n, int k, int MAX_A) {
  // Construct array so that for X = some value <= MAX_A,
  // sum(min(ai, X)) = X*k - 1 to create a tight "m" boundary.
  // Approach: use k-1 elements = X, one element = X-1, rest 0.
  a.assign(n, 0);
  if (k > n)
    k = n;
  int X = min(MAX_A, max(1, rnd.next(1, max(1, 1000)))); // small X for safety
  // ensure X >= 1
  for (int i = 0; i < k - 1; ++i)
    a[i] = X;
  if (k - 1 < n)
    a[k - 1] = max(0, X - 1);
  // rest are zero
  // if X > MAX_A (shouldn't) we cap earlier
}

void gen_edge_case_k_equals_n(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  // For k = n, answer is min(ai) basically. Create a mix where min is small.
  a.resize(n);
  for (int i = 0; i < n; ++i)
    a[i] = rnd.next(0, MAX_A);
  // ensure at least one very small min
  a[rnd.next(0, n - 1)] = rnd.next(0, min(5, MAX_A));
}

void gen_many_small_large_groups(vector<ll> &a, int n, int /*k*/, int MAX_A) {
  a.assign(n, 0);
  int big_group = max(1, n / 10);
  for (int i = 0; i < big_group; ++i)
    a[i] = MAX_A;
  for (int i = big_group; i < n; ++i) {
    if (rnd.next(0, 4) == 0)
      a[i] = rnd.next(1, min(100, MAX_A));
    else
      a[i] = rnd.next(0, 2);
  }
}

// main generator: pick a pattern for each test according to index cycling
int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int T = opt<int>("T", 10);
  int N = opt<int>("N", 50);
  int MAX_A = opt<int>("MAX_A", 1000);

  // validations
  if (T < 1) {
    cerr << "T must be >= 1\n";
    return 1;
  }
  if (N < T) {
    cerr << "N must be >= T (each test needs n >= 1)\n";
    return 1;
  }
  if (N > 200000) {
    cerr << "N must be <= 2e5\n";
    return 1;
  }
  if (MAX_A < 0) {
    cerr << "MAX_A must be >= 0\n";
    return 1;
  }
  if (T > 1000)
    cerr << "Warning: T > 1000 (statement limit)\n";

  // partition N into T parts >= 1
  int remN = N - T;
  vector<int> extraN(T, 0);
  if (remN > 0)
    extraN = rnd.partition(T, remN);
  vector<int> ns(T);
  for (int i = 0; i < T; ++i)
    ns[i] = 1 + extraN[i];

  cout << T << '\n';

  // list of pattern functions (we will cycle through and randomize)
  vector<int> pattern_ids = {
      0,  // all zeros
      1,  // single large first
      2,  // single large last
      3,  // all ones
      4,  // all equal large
      5,  // many ones + some large
      6,  // alternating big/zero
      7,  // increasing sequence
      8,  // decreasing sequence
      9,  // arithmetic progression
      10, // powers of two
      11, // fibonacci-like
      12, // random uniform
      13, // heavy tail zipf
      14, // border sum = X*k -1
      15, // k == n edge case
      16  // many small and large groups
  };

  for (int ti = 0; ti < T; ++ti) {
    int n = ns[ti];
    // pick k with bias toward interesting extremes sometimes
    int pick = rnd.next(1, 100);
    int k;
    if (pick <= 12)
      k = 1; // many k=1 (easy but checks sum)
    else if (pick <= 24)
      k = n; // many k=n (min checks)
    else if (pick <= 50)
      k = rnd.next(1, max(1, min(n, 5))); // small k
    else if (pick <= 80)
      k = rnd.next(max(1, n / 4), max(1, n)); // medium-large k
    else
      k = rnd.next(1, n); // fully random

    vector<ll> a;
    // select pattern id: cycle + some randomness
    int pid = pattern_ids[(ti + rnd.next(0, (int)pattern_ids.size() - 1)) %
                          (int)pattern_ids.size()];

    switch (pid) {
    case 0:
      gen_all_zeros(a, n, k, MAX_A);
      break;
    case 1:
      gen_single_large(a, n, k, MAX_A, true);
      break;
    case 2:
      gen_single_large(a, n, k, MAX_A, false);
      break;
    case 3:
      gen_all_equal(a, n, k, MAX_A, 1);
      break;
    case 4:
      gen_all_equal(a, n, k, MAX_A, MAX_A);
      break;
    case 5:
      gen_many_ones_some_large(a, n, k, MAX_A);
      break;
    case 6:
      gen_alternating_big_zero(a, n, k, MAX_A);
      break;
    case 7:
      gen_increasing_seq(a, n, k, MAX_A);
      break;
    case 8:
      gen_decreasing_seq(a, n, k, MAX_A);
      break;
    case 9:
      gen_arith_prog(a, n, k, MAX_A);
      break;
    case 10:
      gen_powers_of_two(a, n, k, MAX_A);
      break;
    case 11:
      gen_fibonacci_like(a, n, k, MAX_A);
      break;
    case 12:
      gen_random_uniform(a, n, k, MAX_A);
      break;
    case 13:
      gen_heavy_tail(a, n, k, MAX_A);
      break;
    case 14:
      gen_border_sum_minus_one(a, n, k, MAX_A);
      break;
    case 15:
      gen_edge_case_k_equals_n(a, n, k, MAX_A);
      break;
    case 16:
      gen_many_small_large_groups(a, n, k, MAX_A);
      break;
    default:
      gen_random_uniform(a, n, k, MAX_A);
      break;
    }

    // occasional mixing: shuffle and also sometimes inject a few tiny tweaks to
    // trip ties
    if (rnd.next(0, 4) == 0) {
      // shuffle a bit
      for (int it = 0; it < min(5, n); ++it) {
        int x = rnd.next(0, n - 1);
        int y = rnd.next(0, n - 1);
        swap(a[x], a[y]);
      }
    }

    // occasionally force a tricky boundary where many elements equal each other
    if (rnd.next(0, 9) == 0 && n >= 3) {
      ll v = min<ll>(MAX_A, max(1, rnd.next(1, 1000)));
      for (int i = 0; i < n / 3; ++i)
        a[i] = v;
      for (int i = n / 3; i < n / 3 + n / 10 && i < n; ++i)
        a[i] = v - 1;
    }

    // output this test
    cout << n << ' ' << k << '\n';
    for (int i = 0; i < n; ++i) {
      ll val = cap_ll(a[i], MAX_A);
      // ensure not negative
      if (val < 0)
        val = 0;
      cout << val << (i + 1 == n ? '\n' : ' ');
    }
  }

  return 0;
}
