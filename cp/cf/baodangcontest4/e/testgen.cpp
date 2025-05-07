/**
 * Author: distiled
 */
#include<iostream>
using namespace std;

#include "../testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char * argv[]) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerGen(argc, argv, 1);
  int n = opt<int>("n");
  int small = opt<int>("o");
  int k = rnd.next(1, min(10, n));
  cout << n << ' ' << k << '\n';
  vector<long double> p(n);
  for(int i = 0; i < n; i++) {
    int percent = rnd.next(0, 100);
    p[i] = percent / 100.0;
  }
  auto gen = [&] () -> int {
    int t = rnd.next(0, n - 1);
    if(small) 
      return rnd.next(0, 15);
    else
      return rnd.next(0, 10000);
  };
  println(p);
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    a[i] = gen();
  }
  println(a);
  vector<int> b(n);
  for(int i = 0; i < n; i++) {
    b[i] = gen();
  }
  println(b);
}
