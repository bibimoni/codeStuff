/**
 * Author: distiled
 */
#include <iostream>
using namespace std;

#include "testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char * argv[]) {
  registerGen(argc, argv, 1);
  int t = opt<int>("t");    
  int sub = opt<int>("sub");
  int K = opt<int>("k");
  cout << t << '\n';
  int N;
  if(sub == 1)
    N = 100;
  if(sub == 2)
    N = 1000;
  if(sub == 3)
    N = 5000;
  if(sub == 4) 
    N = (int) 2e5;
  // auto genArr = [&] (vector<int> nums, int n, int k) {
  //   cout << n << '\n';
  //   vector<int> test(n);
  //   int sum = 0;
  //   for(int i = 0; i < n; i++) {
  //     test[i] = nums[rnd.next(0, 1)];
  //     sum += test[i];
  //   }
  //   if(sum < k) {
  //     for(int i = 0; i < n && sum < k; i++) {
  //       sum += k - test[i];
  //       test[i] = k;
  //     }
  //   }
  //   println(test);
  // };
  for(int testc = 0; testc < t; testc++) {
    int n = (N / t), k = rnd.next(2, K);
    vector<int> test(n);
    cout << n << ' ' << k << '\n';
    int sum = 0;
    for(int i = 0; i < n; i++) {
      test[i] = rnd.next(max(k - 3, 0), k - 1);
      sum += test[i];
    }
    if(sum < k) {
      for(int i = 0; i < n && sum < k; i++) {
        sum += (k - 1) - test[i];
        test[i] = (k - 1);
      }
    }
    println(test);
  }
}

