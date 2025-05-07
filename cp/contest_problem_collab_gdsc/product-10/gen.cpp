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
  
  #define int int64_t
  int tt = opt<int>("tt");
  int N = opt<int>("N");
  int MX = opt<int>("MX");
  
  auto v = rnd.partition(tt, N);

  auto pwr = [&] (int val, int x) -> int {
    int t = 1;
    while (x--) {
      t *= val;
    }
    return t;
  };

  auto cnt = [&] (int val, int x) -> int {
    int ret = 0, tmp = val;
    while (val > 0) {
      val /= x;
      ret += 1;
    }
    return pwr(x, ret) > tmp ? ret - 1 : ret;
  };

  println(tt);
  for (int n : v) {
    println(n);
    vector<int> f;
    while (n--) {
      int val = rnd.next(int(1), MX);
      int f_1 = cnt(val, 2);
      int pwr_1 = rnd.next(0LL, f_1);
      int x = int(pwr(2, pwr_1));
      val /= x;
      int f_2 = cnt(val, 5);
      int pwr_2 = rnd.next(0LL, f_2);
      x *= int(pwr(5, pwr_2));
      int f_3 = rnd.next(int(1), int(MX / x));
      x *= f_3;
      f.push_back(x);
    }
    println(f);
  }
}
