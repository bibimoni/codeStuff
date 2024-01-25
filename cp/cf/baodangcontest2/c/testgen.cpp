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

const int MAX_ELEMENT = (int) 1e6;

//sub1: n <= 50, d_i <= 1e5
//sub2: n <= 1e3, d_i <= 50
//sub3: n <= 2e5, d_i <= 1e6
int testNum = 1, prevTests = 19;

void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  // int n = rnd(1, 50); 
  // int n = 50;
  // int n = rnd(51, 1e3);
  // int n = 1e3;
  // int n = rnd(1e3, 2e5);
  int n = 2e5;
  vector<int> d(n);
  for(int i = 0; i < n; i++) {
    d[i] = rnd(1, MAX_ELEMENT);
  }
  int total = accumulate(d.begin(), d.end(), 0ll);
  dbg(total);
  int prb = rnd(1, 5);
  inp << n << ' ' << rnd(n, min(total, (prb == 5 ? total : n + 100))) << '\n';
  for(int i : d) inp << i << ' ';
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

