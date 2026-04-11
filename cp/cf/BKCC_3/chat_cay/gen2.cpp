// gen_tree_queries_partition.cpp
// Compile:
//   g++ -std=c++17 gen_tree_queries_partition.cpp -O2 -o gen
// Example:
//   ./gen -tests=5 -sumN=50 -sumQ=120 -amin=-1000 -amax=1000 -seed=42
//
// Requires testlib.h.

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv) {
  registerGen(argc, argv);

  int T = opt<int>("tests", 1);
  int sumN = opt<int>("sumN", 10);
  int sumQ = opt<int>("sumQ", 10);
  int A_MIN = opt<int>("amin", -1000);
  int A_MAX = opt<int>("amax", 1000);
  int updRange = opt<int>("upd", 1000); // magnitude for type-2 updates

  if (T < 1) {
    cerr << "tests must be >= 1\n";
    return 1;
  }
  if (sumN < T) {
    cerr << "sumN must be at least tests (each testcase needs n>=1)\n";
    return 1;
  }
  if (A_MIN > A_MAX) {
    cerr << "amin <= amax required\n";
    return 1;
  }

  // Give each test a base of 1 node, then partition the remaining (sumN - T)
  int remN = sumN - T;
  vector<int> extraN;
  if (remN > 0)
    extraN = rnd.partition(T, remN);
  else
    extraN = vector<int>(T, 0);

  vector<int> ns(T);
  for (int i = 0; i < T; ++i)
    ns[i] = 1 + extraN[i];

  // Minimal required Q per test: minQi = max(1, n-1)
  ll minQsum = 0;
  vector<int> minQ(T);
  for (int i = 0; i < T; ++i) {
    minQ[i] = max(1, ns[i] - 1);
    minQsum += minQ[i];
  }

  if (sumQ < minQsum) {
    cerr << "sumQ too small. Need at least " << minQsum
         << " given distribution of n's.\n";
    return 1;
  }

  int remQ = sumQ - (int)minQsum;
  vector<int> extraQ;
  if (remQ > 0)
    extraQ = rnd.partition(T, remQ);
  else
    extraQ = vector<int>(T, 0);

  vector<int> qs(T);
  for (int i = 0; i < T; ++i)
    qs[i] = minQ[i] + extraQ[i];

  // Output T
  cout << T << '\n';

  // For each test produce n, a_i, edges (tree), q, queries
  for (int ti = 0; ti < T; ++ti) {
    int n = ns[ti];
    int q = qs[ti];

    cout << n << '\n';

    // a_i
    for (int i = 1; i <= n; ++i) {
      int val = rnd.next(A_MIN, A_MAX);
      cout << val << (i == n ? '\n' : ' ');
    }

    // Build random tree (edges 1..n-1)
    vector<pair<int, int>> edges;
    edges.reserve(max(0, n - 1));
    for (int v = 2; v <= n; ++v) {
      int u = rnd.next(1, v - 1); // random parent among previous nodes
      edges.emplace_back(u, v);
    }
    for (auto &e : edges)
      cout << e.first << ' ' << e.second << '\n';

    // Build queries
    vector<string> queries;
    queries.reserve(q);

    // Add deletions (exactly n-1 distinct deletions if n>=2)
    if (n >= 2) {
      vector<int> dels(n - 1);
      for (int i = 0; i < n - 1; ++i)
        dels[i] = i + 1;
      shuffle(dels.begin(), dels.end());
      for (int id : dels)
        queries.push_back("1 " + to_string(id));
    }

    int rem = q - (int)queries.size();
    for (int k = 0; k < rem; ++k) {
      int typ = rnd.next(1, 10);
      if (typ <= 6) {
        int u = rnd.next(1, n);
        int y = rnd.next(-updRange, updRange);
        queries.push_back("2 " + to_string(u) + " " + to_string(y));
      } else {
        queries.push_back("3");
      }
    }

    // Shuffle so deletions intersperse with other queries
    shuffle(queries.begin(), queries.end());

    cout << q << '\n';
    for (auto &line : queries)
      cout << line << '\n';
  }

  return 0;
}
