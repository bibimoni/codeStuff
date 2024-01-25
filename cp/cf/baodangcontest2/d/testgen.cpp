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

const int MAX_ELEMENT = (int) 15;
int testNum = 50, prevTests = 0;

void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  int t = rnd(100, 1e4);
  inp << t << '\n';
  //cout << t << '\n';
  while(t--) {
    int n = rnd(3, 2e5);
    int ans = rnd(1, 3);
    int edges;
    if(ans == 1) {
      edges = rnd(0, n - 2);
    }
    else if(ans == 2) {
      edges = n - 1;
    }
    else {
      edges = rnd(n, min(n * (n - 1) / 2ll, (int) 1e9));
    }
    int x = rnd(1, (int) 1e9 / edges);
    int m = min({edges * x + rnd(0, x - 1), n * (n - 1) / 2, (int) 1e9});
    inp << n << ' ' << m << ' ' << x << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

