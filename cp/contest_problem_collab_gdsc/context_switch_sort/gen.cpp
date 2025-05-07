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
  
  int tt = opt<int>("tt");
  int N = opt<int>("N");
  int MN = opt<int>("MN");
  int MX = opt<int>("MX");

  println(tt);
  while (tt--) {
    int n = rnd.next(MN, N);
    println(n);
    auto id = rnd.distinct(n, 1, MX);
    for (int i = 0; i < n; i++) {
      cout << id[i] << ' ' << rnd.next(1, MX) << '\n';
    }
  }

}
