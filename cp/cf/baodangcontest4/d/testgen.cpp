/**
 * Author: distiled
 */
#include<iostream>
using namespace std;

#include "testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char * argv[]) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerGen(argc, argv, 1);
  int t = opt<int>("t");
  int N = opt<int>("n");
  cout << t << '\n';
  auto v = rnd.partition(t, N);
  auto qq = rnd.partition(t, N);
  int cur = 0;
  for (int prod : v) {
    int n = rnd.next(int(1), max(int(1), (int) sqrt(prod)));
    int m = max(prod / n, int(1));
    cout << n << ' ' << m << '\n';
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) 
        cout << rnd.next(int(0), int(1e6)) << " \n"[j == m - 1];
    int q = qq[cur++];
    cout << q << '\n';
    for(int i = 0; i < q; i++) {
      int small = rnd.next(0, 1);
      int k = rnd.next(int(1), int(1e6));
      if(small) {
        int a = rnd.next(1, max(n / 10, 1));
        int b = rnd.next(1, max(m / 10, 1));
        int c = rnd.next(max(a, n * 9 / 10), n);
        a = min(a, c);
        int d = rnd.next(max(b, m * 9 / 10), m);
        b = min(b, d);
        cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << '\n';
      }
      else {
        int a = rnd.next(1, n);
        int b = rnd.next(1, m);
        int c = rnd.next(a, n);
        int d = rnd.next(b, m);
        cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << '\n';
      }
    }
  }
}

