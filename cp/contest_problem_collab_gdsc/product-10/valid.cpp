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
  int testCount = inf.readInt(1, 10000, "testCount");
  inf.readEoln();
  int sum_n = n;
  for (int i = 0; i < testCount; i++) {
    setTestCase(i + 1);
    
    int n = inf.readInt(1, 200'000, "n");
    sum_n += n;
    inf.readEoln();
    inf.readInts(1, 1'000'000'000'000, "a~");
      inf.readEoln();
  }
  inf.readEof();
}
