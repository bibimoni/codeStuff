#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

inline long long key_of(int x, int y, int n) {
  return (long long)(x - 1) * (long long)n + (long long)(y - 1);
}

int main(int argc, char **argv) {
  registerGen(argc, argv);

  int T = opt<int>("T", 1);
  int totalN = opt<int>("N", 500000);
  int totalQ = opt<int>("Q", 500000);

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

  int sq = 0;
  for (int ti = 0; ti < T; ++ti) {
    int n = ns[ti];
    int q = qs[ti];

    ll m_target = min<ll>(500000, (ll)n * 3);
    if (m_target > (ll)n * (ll)n)
      m_target = (ll)n * (ll)n;
    m_target = max<ll>(1, m_target);

    set<long long> used;
    vector<pii> points;
    points.reserve((size_t)min(m_target, (ll)500000));

    vector<int> k_choices = {2, 3, 4, 5, 6, 1};

    vector<tuple<int, int, int>> blocks;
    blocks.reserve(max(1, (int)(m_target / 3)));

    auto place_blocks_k = [&](int k) {
      if (k > n)
        return;
      int step = k + 1;
      for (int u = 1; u <= n - k + 1 && (ll)points.size() < m_target;
           u += step) {
        for (int v = 1; v <= n - k + 1 && (ll)points.size() < m_target;
             v += step) {
          bool ok = true;
          if (used.count(key_of(u, v, n)) ||
              used.count(key_of(u + k - 1, v + k - 1, n)))
            ok = false;
          if (!ok)
            continue;
          vector<int> perm(k);
          for (int i = 0; i < k; ++i)
            perm[i] = i;
          shuffle(perm.begin(), perm.end());

          bool collision = false;
          for (int i = 0; i < k; ++i) {
            int x = u + i;
            int y = v + perm[i];
            long long key = key_of(x, y, n);
            if (used.count(key)) {
              collision = true;
              break;
            }
          }
          if (collision)
            continue;

          for (int i = 0; i < k; ++i) {
            int x = u + i;
            int y = v + perm[i];
            long long key = key_of(x, y, n);
            used.insert(key);
            points.emplace_back(x, y);
          }
          blocks.emplace_back(k, u, v);
          if ((ll)points.size() >= m_target)
            return;
        }
      }
    };

    for (int pass = 0; pass < 3 && (ll)points.size() < m_target; ++pass) {
      for (int kc : k_choices) {
        place_blocks_k(kc);
        if ((ll)points.size() >= m_target)
          break;
      }
    }

    if ((ll)points.size() < m_target) {
      for (int x = 1; x <= n && (ll)points.size() < m_target; ++x) {
        for (int y = 1; y <= n && (ll)points.size() < m_target; ++y) {
          long long key = key_of(x, y, n);
          if (!used.count(key)) {
            used.insert(key);
            points.emplace_back(x, y);
          }
        }
      }
    }

    int yes_want = q / 2;
    int no_want = q - yes_want;

    vector<tuple<int, int, int>> queries;
    queries.reserve(q);

    vector<int> idx_blocks(blocks.size());
    for (size_t i = 0; i < blocks.size(); ++i)
      idx_blocks[i] = (int)i;
    shuffle(idx_blocks.begin(), idx_blocks.end());

    int used_block_idx = 0;
    for (int i = 0; i < yes_want; ++i) {
      if (used_block_idx < (int)idx_blocks.size()) {
        auto [k, u, v] = blocks[idx_blocks[used_block_idx++]];
        queries.emplace_back(k, u, v);
      } else {
        if (!points.empty()) {
          auto p = points[rnd.next(0, (int)points.size() - 1)];
          int x = p.first, y = p.second;
          queries.emplace_back(1, x, y);
        } else {
          queries.emplace_back(1, 1, 1);
        }
      }
    }

    int no_empty = no_want / 2;
    int no_broken = no_want - no_empty;

    int maxKempty = min(n, 10);
    int attemptsEmpty = max(200, no_empty * 3);
    for (int i = 0; i < no_empty; ++i) {
      bool made = false;
      for (int a = 0; a < attemptsEmpty && !made; ++a) {
        int k = rnd.next(1, maxKempty);
        if (k > n)
          k = n;
        if (n - k + 1 <= 0)
          continue;
        int u = rnd.next(1, n - k + 1);
        int v = rnd.next(1, n - k + 1);
        bool any = false;
        vector<pair<int, int>> samples;
        samples.emplace_back(u, v);
        samples.emplace_back(u + k - 1, v + k - 1);
        samples.emplace_back(u, v + k - 1);
        samples.emplace_back(u + k - 1, v);
        samples.emplace_back(u + k / 2, v + k / 2);
        for (auto &s : samples) {
          long long key = key_of(s.first, s.second, n);
          if (used.count(key)) {
            any = true;
            break;
          }
        }
        if (any)
          continue;
        bool full_empty = true;
        for (int ii = 0; ii < k && full_empty; ++ii)
          for (int jj = 0; jj < k; ++jj)
            if (used.count(key_of(u + ii, v + jj, n))) {
              full_empty = false;
              break;
            }
        if (!full_empty)
          continue;
        queries.emplace_back(k, u, v);
        made = true;
      }
      if (!made) {
        for (int x = 1; x <= n && !made; ++x) {
          for (int y = 1; y <= n && !made; ++y) {
            if (!used.count(key_of(x, y, n))) {
              queries.emplace_back(1, x, y);
              made = true;
            }
          }
        }
        if (!made)
          queries.emplace_back(1, 1, 1);
      }
    }

    int attemptsBroken = max(50, no_broken * 2);
    for (int i = 0; i < no_broken; ++i) {
      bool done = false;
      for (int a = 0; a < attemptsBroken && !done; ++a) {
        if (blocks.empty())
          break;
        int bi = rnd.next(0, (int)blocks.size() - 1);
        auto [k, u, v] = blocks[bi];
        vector<pii> empties;
        empties.reserve(k * k);
        for (int ii = 0; ii < k; ++ii)
          for (int jj = 0; jj < k; ++jj) {
            int x = u + ii, y = v + jj;
            long long key = key_of(x, y, n);
            if (!used.count(key))
              empties.emplace_back(x, y);
          }
        if (empties.empty())
          continue;
        auto p = empties[rnd.next(0, (int)empties.size() - 1)];
        used.insert(key_of(p.first, p.second, n));
        points.emplace_back(p.first, p.second);
        queries.emplace_back(k, u, v);
        done = true;
      }
      if (!done) {
        bool placed = false;
        for (int tries = 0; tries < 50 && !placed; ++tries) {
          int x = rnd.next(1, n);
          int y = rnd.next(1, n);
          long long key = key_of(x, y, n);
          if (used.count(key))
            continue;
          used.insert(key);
          points.emplace_back(x, y);
          placed = true;
        }
        if (!points.empty()) {
          auto p = points[rnd.next(0, (int)points.size() - 1)];
          int x = p.first, y = p.second;
          int u = max(1, min(x, n - 1));
          int v = max(1, min(y, n - 1));
          queries.emplace_back(2, u, v);
        } else {
          queries.emplace_back(1, 1, 1);
        }
      }
    }

    while ((int)queries.size() < q) {
      if (n >= 1) {
        int k = 1;
        bool found = false;
        for (int x = 1; x <= n && !found; ++x)
          for (int y = 1; y <= n && !found; ++y) {
            if (!used.count(key_of(x, y, n))) {
              queries.emplace_back(k, x, y);
              found = true;
            }
          }
        if (!found)
          queries.emplace_back(1, 1, 1);
      } else
        queries.emplace_back(1, 1, 1);
    }
    if ((int)queries.size() > q) {
      shuffle(queries.begin(), queries.end());
      queries.resize(q);
    }

    shuffle(queries.begin(), queries.end());

    set<pair<int, int>> ps{points.begin(), points.end()};
    while (ps.size() > 500'000) {
      ps.erase(*ps.rbegin());
    }
    cout << n << ' ' << ps.size() << '\n';
    for (auto &p : ps)
      cout << p.first << ' ' << p.second << '\n';

    q = min(500'000 - sq, q);
    cout << q << '\n';
    for (int i = 0; i < q; i++) {
      auto tq = queries[i];
      int k, u, v;
      tie(k, u, v) = tq;
      if (k < 1)
        k = 1;
      if (k > n)
        k = n;
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
