// gen_rice_squares.cpp
// Generator for the "beautiful square" problem.
// Usage (example):
//   ./gen -T=10 -N=200 -Q=400 -seed=42 > input.txt
//
// Requires testlib.h in include path.

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

// encode a coordinate (x,y) into a single 64-bit key to store in unordered_set
inline long long key_of(int x, int y, int n) {
  return (long long)(x - 1) * n + (y - 1);
}

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int T = opt<int>("T", 1);
  int totalN = opt<int>("N", 1);
  int totalQ = opt<int>("Q", 1);

  int remN = totalN - T;
  vector<int> extraN(T, 0);
  if (remN > 0)
    extraN = rnd.partition(T, remN);
  vector<int> ns(T);
  for (int i = 0; i < T; ++i)
    ns[i] = 1 + extraN[i];

  int remQ = max(0, totalQ - T);
  vector<int> extraQ(T, 0);
  if (remQ > 0)
    extraQ = rnd.partition(T, remQ);
  vector<int> qs(T);
  for (int i = 0; i < T; ++i)
    qs[i] = 1 + extraQ[i];

  cout << T << '\n';

  for (int ti = 0; ti < T; ++ti) {
    int n = ns[ti];
    int q = qs[ti];

    set<long long> used;

    vector<pair<int, int>> points;
    points.reserve(min(n * n, 1000));
    int yes_want = q / 2;
    int no_want = q - yes_want;

    struct Query {
      int k, u, v;
      bool answer;
    };
    vector<Query> queries;
    queries.reserve(q);

    auto subgrid_is_empty = [&](int u, int v, int k) -> bool {
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
          if (used.count(key_of(u + i, v + j, n)))
            return false;
        }
      }
      return true;
    };

    int attemptsPerYes = 400;
    for (int it = 0; it < yes_want; ++it) {
      bool placed = false;
      int maxK = min(n, max(1, min(30, n)));
      for (int try_k_attempt = 0; try_k_attempt < 3 && !placed;
           ++try_k_attempt) {
        int k;
        if (try_k_attempt == 0)
          k = rnd.next(1, max(1, min(6, maxK)));
        else if (try_k_attempt == 1)
          k = rnd.next(1, maxK);
        else
          k = rnd.next(1, maxK);

        if (k > n)
          continue;
        if (n - k + 1 <= 0)
          continue;

        for (int a = 0; a < attemptsPerYes && !placed; ++a) {
          int u = rnd.next(1, n - k + 1);
          int v = rnd.next(1, n - k + 1);
          if (!subgrid_is_empty(u, v, k))
            continue;

          vector<int> perm(k);
          for (int i = 0; i < k; ++i)
            perm[i] = i;
          shuffle(perm.begin(), perm.end());

          bool collision = false;
          for (int i = 0; i < k; ++i) {
            int x = u + i, y = v + perm[i];
            long long key = key_of(x, y, n);
            if (used.count(key)) {
              collision = true;
              break;
            }
          }
          if (collision)
            continue;

          for (int i = 0; i < k; ++i) {
            int x = u + i, y = v + perm[i];
            long long key = key_of(x, y, n);
            used.insert(key);
            points.emplace_back(x, y);
          }

          queries.push_back({k, u, v, true});
          placed = true;
        }
      }
      if (!placed) {
        bool ok = false;
        for (int tries = 0; tries < 200 && !ok; ++tries) {
          int x = rnd.next(1, n);
          int y = rnd.next(1, n);
          long long key = key_of(x, y, n);
          if (used.count(key))
            continue;
          used.insert(key);
          points.emplace_back(x, y);
          queries.push_back({1, x, y, true});
          ok = true;
        }
        if (!ok) {
          if (!points.empty()) {
            auto p = points[rnd.next(0, (int)points.size() - 1)];
            queries.push_back({1, p.first, p.second, true});
          } else {
            used.insert(key_of(1, 1, n));
            points.emplace_back(1, 1);
            queries.push_back({1, 1, 1, true});
          }
        }
      }
    }

    int no_attempts = 300;
    for (int it = 0; it < no_want; ++it) {
      bool made = false;
      // choose a mode
      int mode = rnd.next(1, 3);
      if (mode == 1) {
        int maxK = min(n, max(1, min(40, n)));
        for (int a = 0; a < no_attempts && !made; ++a) {
          int k = rnd.next(1, maxK);
          if (n - k + 1 <= 0)
            continue;
          int u = rnd.next(1, n - k + 1);
          int v = rnd.next(1, n - k + 1);
          bool empty = true;
          for (int i = 0; i < k && empty; ++i)
            for (int j = 0; j < k; ++j)
              if (used.count(key_of(u + i, v + j, n))) {
                empty = false;
                break;
              }
          if (!empty)
            continue;
          queries.push_back({k, u, v, false});
          made = true;
        }
      } else if (mode == 2) {
        int maxK = min(n, max(1, min(40, n)));
        for (int a = 0; a < no_attempts && !made; ++a) {
          int k = rnd.next(1, maxK);
          if (n - k + 1 <= 0)
            continue;
          int u = rnd.next(1, n - k + 1);
          int v = rnd.next(1, n - k + 1);
          int cnt = 0;
          for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
              if (used.count(key_of(u + i, v + j, n)))
                ++cnt;
          if (cnt > 0 && cnt < k) {
            queries.push_back({k, u, v, false});
            made = true;
          }
        }
      } else {
        bool done = false;
        for (int pickTry = 0; pickTry < 50 && !done; ++pickTry) {
          if (queries.empty())
            break;
          int idx = rnd.next(0, (int)queries.size() - 1);
          Query q0 = queries[idx];
          if (!q0.answer)
            continue;
          int k = q0.k, u = q0.u, v = q0.v;
          vector<pii> empties;
          for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j) {
              int x = u + i, y = v + j;
              if (!used.count(key_of(x, y, n)))
                empties.emplace_back(x, y);
            }
          if (empties.empty())
            continue;
          auto pr = empties[rnd.next(0, (int)empties.size() - 1)];
          used.insert(key_of(pr.first, pr.second, n));
          points.emplace_back(pr.first, pr.second);
          queries.push_back({k, u, v, false});
          done = true;
          made = true;
        }
        if (!made) {
          for (int a = 0; a < no_attempts && !made; ++a) {
            int k = 1;
            int u = rnd.next(1, n - k + 1);
            int v = rnd.next(1, n - k + 1);
            if (used.count(key_of(u, v, n)))
              continue;
            queries.push_back({k, u, v, false});
            made = true;
          }
        }
      }
      if (!made) {
        // produce trivial No at (1,1) with k= min(1,n)
        queries.push_back({1, 1, 1, false});
      }
    }

    shuffle(queries.begin(), queries.end());

    int m = (int)points.size();
    int extra_try = min(n * n - m, n);
    if (extra_try > 0 && rnd.next(0, 2) == 0) {
      int toAdd = rnd.next(0, extra_try);
      for (int i = 0; i < toAdd; ++i) {
        for (int tries = 0; tries < 200; ++tries) {
          int x = rnd.next(1, n);
          int y = rnd.next(1, n);
          long long key = key_of(x, y, n);
          if (used.count(key))
            continue;
          used.insert(key);
          points.emplace_back(x, y);
          break;
        }
      }
    }
    m = (int)points.size();

    set<pair<int, int>> ps{points.begin(), points.end()};
    cout << n << ' ' << ps.size() << '\n';
    for (auto &p : ps)
      cout << p.first << ' ' << p.second << '\n';

    cout << (int)queries.size() << '\n';
    for (auto &qq : queries) {
      int k = qq.k;
      if (k < 1)
        k = 1;
      if (k > n)
        k = n;
      int u = qq.u, v = qq.v;
      if (u < 1)
        u = 1;
      if (v < 1)
        v = 1;
      if (u > n - k + 1)
        u = max(1, n - k + 1);
      if (v > n - k + 1)
        v = max(1, n - k + 1);
      cout << k << ' ' << u << ' ' << v << '\n';
    }
  }

  return 0;
}
