/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

#define int            long long
#define all(x)         x.begin(), x.end()

const int MAX_ELEMENT = (int) 1e5;
int testNum = 1, prevTests = 32;
/*
 n <= 10 (10 tests) (done)
 n <= 10^2 (10 tests)
 n <= 10^4 (8 tests)
 n <= 2*10^5 (6 tests)
 all subtask need to have a 0 case.
 there must be a test with the result more than the MODULO
*/

void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  // int n = rnd(10001, 2e5);
  int n = (int) 2e5;
  inp << n << '\n';
  //base
  for(int i = 0; i < n; i++) {
    int currChar = rnd(1, 35);
    if(currChar == 1) {
      int rand = rnd(1, 25);
      inp << ((char) (rand + 'a'));
    }
    else if(currChar > 1 && currChar <= 18) {
      inp << 'a';
    }
    else {
      inp << 'c';
    }
  }
  // zero case
  // for(int i = 0; i < n; i++) {
  //   int rand = rnd(1, 25);
  //   inp << ((char) (rand + 'a'));    
  // }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

