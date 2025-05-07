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
  registerValidation(argc, argv);  
  int testCount = inf.readInt(1, 1000, "testCount");
  inf.readEoln();
  int sum_n = 0, sum_m = 0;
  for (int i = 0; i < testCount; i++) {
    setTestCase(i + 1);
    
    int n = inf.readInt(1, 200'000, "n");
    sum_n += n;
    inf.readSpace();

    int m = inf.readInt(1, 500'000, "m");
    sum_m += m;
    inf.readEoln();

    while (m--) {
      inf.readInts(2, 1, n, "uv");
      inf.readEoln();      
    }
  }
  ensure(sum_n <= 200'000);
  ensure(sum_m <= 500'000);
  inf.readEoln();
  inf.readEof();
}
