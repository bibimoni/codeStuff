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

int prevTests = 0, testNum = 50;
int j = 0, i = 0;
char x[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
int y[] = {1, 2, 3, 4, 5, 6, 7, 8};
void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());

  if(x[i] != 'e' || y[j] != 4) inp << x[i] << y[j];
  j++;
  if(j == 8) {
    j = 0, i++;
  }
}


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

