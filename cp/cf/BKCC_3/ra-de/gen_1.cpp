#include "testlib.h"
#include <bits/stdc++.h>

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

vector<int64_t> all_primes;

void sieve(int64_t n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int64_t p = 2; p * p <= n; p++) {
    if (is_prime[p]) {
      for (int64_t i = p * p; i <= n; i += p)
        is_prime[i] = false;
    }
  }
  for (int64_t p = 2; p <= n; p++) {
    if (is_prime[p]) {
      all_primes.push_back(p);
    }
  }
}

void gen_b(vector<int64_t> &b, int m, int64_t max_b, int type) {
  if (m == 0 || all_primes.empty())
    return;

  if (type == 5 || type == 6 || type == 7) {
    int unique_count = min((int)all_primes.size(), rnd.next(1, 10));
    vector<int64_t> pool;
    for (int i = 0; i < unique_count; ++i) {
      pool.push_back(all_primes[rnd.next(all_primes.size())]);
    }
    for (int i = 0; i < m; ++i) {
      b.push_back(pool[rnd.next(pool.size())]);
    }
  } else {
    for (int i = 0; i < m; ++i) {
      b.push_back(all_primes[rnd.next(all_primes.size())]);
    }
  }
  shuffle(b.begin(), b.end());
}

int64_t build_val(const vector<int64_t> &prime_pool, int64_t max_val) {
  if (prime_pool.empty() || max_val <= 0)
    return 1;

  __int128_t val = 1;
  int num_factors = rnd.next(0, 25);

  for (int i = 0; i < num_factors; ++i) {
    int64_t p = prime_pool[rnd.next(prime_pool.size())];
    if (val > max_val / p) {
      break;
    }
    val *= p;
  }
  if (val == 0)
    return 1;
  return (int64_t)val;
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);

  int n = opt<int>("N");
  int m = opt<int>("M");
  int64_t max_a = opt<int64_t>("MA");
  int64_t max_b = opt<int64_t>("MB");
  int type = opt<int>("Typ");

  // Enforce problem constraints
  if (max_a > 2000000)
    max_a = 2000000;
  if (max_b > 2000000)
    max_b = 2000000;
  if (max_a < 1)
    max_a = 1;
  if (max_b < 2)
    max_b = 2;

  if (type == 1) {
    m = 0;
    println(n, m);
    vector<int64_t> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rnd.next(1LL, max_a));
    }
    println(a);
    return 0;
  }

  sieve(max_b);
  vector<int64_t> b;
  gen_b(b, m, max_b, type);

  set<int64_t> b_unique_primes_set(b.begin(), b.end());
  vector<int64_t> b_primes(b_unique_primes_set.begin(),
                           b_unique_primes_set.end());
  vector<int64_t> other_primes;

  if (all_primes.size() < 500) {
    for (int64_t p : all_primes) {
      if (b_unique_primes_set.find(p) == b_unique_primes_set.end()) {
        other_primes.push_back(p);
      }
    }
  } else {
    for (int64_t p : all_primes) {
      if (!binary_search(b_primes.begin(), b_primes.end(), p)) {
        other_primes.push_back(p);
      }
    }
  }

  vector<int64_t> a(n);
  for (int i = 0; i < n; ++i) {
    int64_t r = 1, b_part = 1;

    switch (type) {
    case 2:
    case 5:
      r = build_val(other_primes, rnd.next(1LL, max_a));
      if (r == 0)
        r = 1;
      b_part = build_val(b_primes, max_a / r);
      break;

    case 3:
    case 6:
      r = 1;
      b_part = build_val(b_primes, max_a);
      break;

    case 4:
    case 7:
      r = build_val(other_primes, max_a);
      b_part = 1;
      break;

    default:
      r = rnd.next(1LL, max_a);
      b_part = 1;
      break;
    }

    __int128_t val = (__int128_t)r * b_part;
    if (val > max_a || val <= 0) {
      val = rnd.next(1LL, max_a);
    }
    a[i] = (int64_t)val;
  }

  println(n, m);
  println(a);
  if (m > 0) {
    println(b);
  }

  return 0;
}
