// gen.cpp
// Compile: g++ -std=c++17 gen.cpp -O2 -o gen
// Requires testlib.h (Polygon / emaxx's testlib)

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static void fill_random_density(vector<string> &g, int p_percent) {
  int n = (int)g.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (rnd.next(0, 99) < p_percent)
        g[i][j] = '#';
}

static void fill_checkerboard(vector<string> &g) {
  int n = (int)g.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      g[i][j] = ((i + j) % 2 == 0) ? '#' : '.';
}

static void fill_diagonal(vector<string> &g) {
  int n = (int)g.size();
  for (int i = 0; i < n; ++i)
    g[i][i] = '#';
}

static void fill_plus(vector<string> &g) {
  int n = (int)g.size();
  int mid = n / 2;
  for (int i = 0; i < n; ++i) {
    g[mid][i] = '#';
    g[i][mid] = '#';
  }
}

static void fill_stripes(vector<string> &g, bool row_based) {
  int n = (int)g.size();
  for (int i = 0; i < n; ++i) {
    bool fill = (rnd.next(0, 1) == 1);
    if (row_based) {
      if (fill)
        for (int j = 0; j < n; ++j)
          g[i][j] = '#';
    } else {
      if (fill)
        for (int j = 0; j < n; ++j)
          g[j][i] = '#';
    }
  }
}

static void fill_blocks(vector<string> &g, int blocks) {
  int n = (int)g.size();
  for (int b = 0; b < blocks; ++b) {
    int h = rnd.next(1, max(1, n / 2));
    int w = rnd.next(1, max(1, n / 2));
    int r = rnd.next(0, n - h);
    int c = rnd.next(0, n - w);
    for (int i = r; i < r + h; ++i)
      for (int j = c; j < c + w; ++j)
        g[i][j] = '#';
  }
}

int main(int argc, char **argv) {
  registerGen(argc, argv);

  int N = opt<int>("N", 100); // requested maximum n
  int T = opt<int>("T", 1);   // requested number of testcases

  // Enforce problem limits
  if (N < 1)
    N = 1;
  if (T < 1)
    T = 1;
  N = min(N, 100);
  T = min(T, 100);

  cout << T << '\n';
  for (int tc = 0; tc < T; ++tc) {
    // choose n (mix of small and large cases), but always 1..N
    int pick = rnd.next(1, 100);
    int n;
    if (pick <= 8)
      n = 1; // n = 1
    else if (pick <= 20)
      n = rnd.next(1, min(10, N)); // small
    else if (pick <= 60)
      n = rnd.next(1, min(50, N)); // medium
    else
      n = rnd.next(1, N); // up to N

    vector<string> grid(n, string(n, '.'));

    // choose a pattern / class of tests
    int pattern = rnd.next(1, 10);
    switch (pattern) {
    case 1:
      // all dots
      break;
    case 2:
      // all hashes
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          grid[i][j] = '#';
      break;
    case 3:
      // single hash
      grid[rnd.next(0, n - 1)][rnd.next(0, n - 1)] = '#';
      break;
    case 4: {
      // random density
      int p = rnd.next(0, 100);
      fill_random_density(grid, p);
      break;
    }
    case 5:
      // stripes
      fill_stripes(grid, rnd.next(0, 1) == 1);
      break;
    case 6:
      // blocks
      fill_blocks(grid, rnd.next(1, max(1, n / 4)));
      break;
    case 7:
      // checkerboard when reasonable
      if (n <= 200)
        fill_checkerboard(grid);
      else
        fill_random_density(grid, 50);
      break;
    case 8:
      // diagonal with sprinkle
      fill_diagonal(grid);
      fill_random_density(grid, max(0, min(20, 100 / max(1, n))));
      break;
    case 9:
      // plus sign
      fill_plus(grid);
      if (rnd.next(0, 1) == 1)
        fill_blocks(grid, 1);
      break;
    case 10:
    default:
      // mix
      fill_random_density(grid, rnd.next(0, 60));
      if (rnd.next(0, 3) == 0) {
        int k = rnd.next(1, max(1, n / 5));
        for (int t = 0; t < k; ++t) {
          if (rnd.next(0, 1) == 1) {
            int r = rnd.next(0, n - 1);
            for (int j = 0; j < n; ++j)
              grid[r][j] = '#';
          } else {
            int c = rnd.next(0, n - 1);
            for (int i = 0; i < n; ++i)
              grid[i][c] = '#';
          }
        }
      }
      break;
    }

    // small tweak: create a thin diagonal of dots in otherwise dense grids
    // sometimes
    if (n >= 3 && rnd.next(0, 9) == 0) {
      for (int i = 0; i < n; ++i)
        grid[i][(i + 1) % n] = '.';
    }

    cout << n << '\n';
    for (int i = 0; i < n; ++i)
      cout << grid[i] << '\n';
  }

  return 0;
}
