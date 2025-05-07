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
/*
sub 1:
1-5: maxE = 100
6-15: maxE = 1e5
16 - 25: maxE = 1e9
sub 2:
26 - 30: maxE = 100
31 - 40: maxE = 1e5
40 - 50: maxE = 1e9
*/

  MAXELEMENT = (int) 1e9;
int testNum = 1, prevTests = 50;

void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  int sub = rnd(sub2, sub2); //range for total N
  // randomize number of test ranging from 1 to total N
  //int t = rnd(1, max(1ll, sub / rnd(1, 10)));
  int t = 10;
  inp << t << '\n'; // print number of test
  int NforEachSub = sub / t; // make sure number of test doesnt go out of total N (sub)
  //int NforEachSub = 100;
  int maxBoundForElement = rnd(1, MAXELEMENT); // want k for each number is small or big
  for(int i = 1; i <= t; i++) {
    int makeAllPairNotLargerThanK = rnd(1, 3);
    if(makeAllPairNotLargerThanK == 1) {
      int n = NforEachSub; // print n
      int k = rnd(1, maxBoundForElement); // print k is between a specific range
      inp << n << ' ' << k << '\n';
      vector<int> a(n);
      a[0] = rnd(1, max(1ll, k / 2));
      for(int i = 1; i < n; i++) {
        a[i] = rnd(1ll, max(1ll, k / 2));
      }
      random_shuffle(all(a));
      for(int i : a) inp << i << ' ';
      inp << '\n';
      continue;
    }
    bool can = rnd(0, 1); // check if i want the answer to be yes or no
    int n = NforEachSub; // print n
    int k = rnd(1, maxBoundForElement); // print k is between a specific range
    inp << n << ' ' << k << '\n';
    for(int i = 0; i < n; i++) {
      inp << rnd(1, maxBoundForElement) << ' ';
    }
    inp << '\n';
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

