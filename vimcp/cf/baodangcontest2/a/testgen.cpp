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

const int sub1 = 1000ll, sub2 = 1000000ll, 
  MAXELEMENT = (int) 1e7;
int testNum = 1, prevTests = 19;

void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  int t = 100;//rnd(1, 100);
  inp << t << '\n'; // print number of test
  for(int i = 1; i <= t; i++) {
    int type = rnd(1, 5);
    if(type == 1) {
      inp << "0 0\n";
    }
    else if(type == 2 || type == 3) {
      int n = rnd(-(sqrt(MAXELEMENT) / 2 - 1), sqrt(MAXELEMENT) / 2 - 1);
      int a = 2 * n + 1, b = (2 * n * n + 2 * n);
      dbg(a, b);
      inp << a << ' ' << b << '\n';
    }
    else {
      inp << rnd(-MAXELEMENT, MAXELEMENT) << ' ' << rnd(-MAXELEMENT, MAXELEMENT) << '\n';
    }
  }
  
  //cout << id * (MAXELEMENT) / testNum  << '\n';
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

