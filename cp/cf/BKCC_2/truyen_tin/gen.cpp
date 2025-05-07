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
  int tt = opt<int>("t");
  int N = opt<int>("N");
  cout << tt << "\n";
  vector<int> par = rnd.partition(tt, N, 1);
  for (int n : par) {
    cout << n << '\n';
    vector<int> message(n);
    for (int i = 0; i < n; i++) {
      message[i] = rnd.next(2);
    }
    println(message);
  }
}
