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


const int sub1 = 1000ll, sub2 = 2e5, 
  MAXELEMENT = (int) 1e6;
int testNum = 1, prevTests = 19;
void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  int sub = rnd(sub2, sub2); //range for total N
  int n = sub, k = rnd(n, n);
  vector<bool> check(n, false);
  vector<int> t(n);
  iota(all(t), 0);
  random_shuffle(all(t));
  inp << n << ' ' << k << '\n';
  for(int i = 0; i < n; i++) inp << rnd(-MAXELEMENT, MAXELEMENT) << ' ';
  for(int i = 0; i < k; i++) {
    inp << t[i] + 1 << '\n';
  }

}


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

