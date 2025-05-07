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
  int sum_q = 0;
  for (int i = 0; i < testCount; i++) {
    setTestCase(i + 1);
    
    int q = inf.readInt(1, 200'000, "q");
    sum_q += q;
    inf.readEoln();

    while (q--) {
      int t = inf.readInt(1, 2, "t");
      inf.readSpace();
      int cnt = 0;
      if (t == 1) {
        int x = inf.readInt(1, int(1e9), "x~");
        inf.readSpace();
        cnt += x;
        int a = inf.readInt(1, int(1e9), "a~");
        inf.readEoln();
      } else {
        int c = inf.readInt(1, int(1e9), "c~");
        inf.readEoln(); 
        cnt -= c;
        ensure(c >= 0);
      }
    }
  }
  ensure(sum_q <= 200'000);
  // inf.readEoln();
  inf.readEof();
}
