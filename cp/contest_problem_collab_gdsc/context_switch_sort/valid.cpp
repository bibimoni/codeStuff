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
  int testCount = inf.readInt(1, 100, "testCount");
  inf.readEoln();
  int sum_q = 0;
  for (int i = 0; i < testCount; i++) {
    setTestCase(i + 1);
    
    int n = inf.readInt(1, 100, "n");
    inf.readEoln();

    vector<int> s;
    for (int k = 0; k < n; k++) {
      s.push_back(inf.readInt(1, 1'000'000, "id"));
      inf.readSpace();
      int _ = inf.readInt(1, 1'000'000, "t");
      inf.readEoln();
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    ensure((int)s.size() == n);
  }
  // inf.readEoln();
  inf.readEof();
}
