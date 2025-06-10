#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  // Total number of test cases
  int T = opt<int>("t");
  int N = opt<int>("N");
  println(T);
  long long total_n = 0;
  auto ns = rnd.partition(T, N);
  for (int tc = 0; tc < T; tc++) {
    int type = rnd.next(1, 5);
    int n = ns[tc];
    long long R, C;
    vector<long long> h, w;

    switch (type) {
    case 1: {
      // Small corner case
      n = 1;
      R = C = rnd.next(1LL, 5LL);
      h = {rnd.next(1LL, 5LL)};
      w = {rnd.next(1LL, 5LL)};
      break;
    }
    case 2: {
      R = rnd.next(1LL, 20LL);
      C = rnd.next(1LL, 20LL);
      h.resize(n);
      w.resize(n);
      for (int i = 0; i < n; i++) {
        long long a = rnd.next(1LL, 5LL);
        long long b = rnd.next(1LL, 5LL);
        h[i] = a * C;
        w[i] = b * R;
      }
      break;
    }
    case 3: {
      R = rnd.next(1LL, 20LL);
      C = rnd.next(1LL, 20LL);
      h.resize(n);
      w.resize(n);
      for (int i = 0; i < n; i++) {
        h[i] = max(1LL, C * rnd.next(1LL, 5LL) - rnd.next(-2, 2));
        w[i] = max(1LL, R * rnd.next(1LL, 5LL) - rnd.next(-2, 2));
      }
      break;
    }
    case 4: {
      R = rnd.next(1LL, 100LL);
      C = rnd.next(1LL, 100LL);
      h.resize(n);
      w.resize(n);
      for (int i = 0; i < n; i++) {
        h[i] = rnd.next(1LL, 100LL);
        w[i] = rnd.next(1LL, 100LL);
      }
      break;
    }
    case 5: {
      // Large stress
      R = rnd.next(1LL, (long long)1e9);
      C = rnd.next(1LL, (long long)1e9);
      h.resize(n);
      w.resize(n);
      for (int i = 0; i < n; i++) {
        h[i] = rnd.next(1LL, (long long)1e9);
        w[i] = rnd.next(1LL, (long long)1e9);
      }
      break;
    }
    }

    // output
    cout << n << " " << R << " " << C << "\n";
    println(h);
    println(w);
  }

  return 0;
}
