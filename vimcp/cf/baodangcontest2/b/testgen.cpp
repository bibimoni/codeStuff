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

const int MAX_ELEMENT = (int) 1e12, MAX_ANS = 1e9;
int testNum = 1, prevTests = 19;

void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  // int n = rnd(1, 1e3);
  // int n = 1e3;
  // int n = rnd(1e3, 1e5);
  // int n = 1e5;
  // int n = rnd(1e5, 2e5);
  int n = 2e5;
  inp << n << '\n';
  int ans = rnd(1, MAX_ANS);
  dbg(ans);
  for(int i = 0; i < n; i++) {
    int mul = rnd(ans, MAX_ELEMENT);
    int t = ans * (mul / ans);
    inp << t << ' ';
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

