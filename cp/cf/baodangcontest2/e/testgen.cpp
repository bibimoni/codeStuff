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
int testNum = 1, prevTests = 19;

char e[] = {'A', 'T', 'G', 'C'};

void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  //int n = rnd(1, 50);
  // int n = 50;
  //int n = rnd(51, 2e5);
  int n = 2e5;
  inp << n << '\n';
  int ans = rnd(1, 5);
  int prev = 4;
  if(ans == 1) {
    dbg("S");
    for(int i = 1; i <= n; i++) {
      int id = rnd(0, 3);
      while(id == prev) id = rnd(0, 3);
      inp << e[id];
      prev = id;
    }
  }
  else {
    int cnt = 0;
    while(cnt < n) {
      int lenWant = rnd(1, max(n / 5, 1ll));
      int id = rnd(0, 3);
      for(int i = 1; i <= lenWant; i++) {
        inp << e[id];
        cnt++;
        if(cnt == n) break;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

