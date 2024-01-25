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


const int sub1 = 10000ll, sub2 = 1000000ll, 
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
int testNum = 1, prevTests = 19;
/*
 increasing
 decreasing
 alternative
 all decreasing then 1 increasing 
 //2 element
*/
void gentest(int id) {
  ofstream os;
  ofstream inp((to_string(id + prevTests) + ".inp").c_str());
  int sub = rnd(sub2, sub2); //range for total N
  // random
  // int n = sub2;
  // inp << n << '\n';
  // for(int i = 0; i < n; i++) {
  //   inp << rnd(1, MAXELEMENT) << ' ';
  // }
  // increasing
  // int n = sub;
  // inp << n << '\n';
  // int prev = rnd(1, MAXELEMENT / (sub));
  // inp << prev << ' ';
  // for(int i = 0; i < n - 1; i++) {
  //   int curr = rnd(min(prev + 1, MAXELEMENT / (n - i + 1)), MAXELEMENT / (n - i + 1));
  //   inp << curr << ' ';
  //   prev = curr;
  // } 
  // decreasing
  // int n = sub;
  // inp << n << '\n';
  // int prev = rnd(1, MAXELEMENT / 1);
  // inp << prev << ' ';
  // for(int i = 0; i < n - 1; i++) {
  //   int curr = rnd(min(prev - 1, MAXELEMENT / (i + 1)), prev - 1);
  //   inp << curr << ' ';
  //   prev = curr;
  // } 
  // alternative
  // int n = sub;
  // inp << n << '\n';
  // int prev = rnd(MAXELEMENT / 2 - 100000, MAXELEMENT / 2 + 100000);
  // bool low = true;
  // for(int i = 0; i < n; i++) {
  //   if(low) {
  //     int curr = rnd(1, max(1ll, prev - 1));
  //     inp << curr << ' ';
  //     prev = curr;
  //   }
  //   else {
  //     int curr = rnd(min(prev + 1, MAXELEMENT), MAXELEMENT);
  //     inp << curr << ' ';
  //     prev = curr;
  //   }
  //   low = !low;
  // }
  // all decreasing then 1 increasing 
  int n = sub;
  inp << n << '\n';
  int prev = rnd(1, MAXELEMENT / 1);
  inp << prev << ' ';
  for(int i = 0; i < n - 2; i++) {
    int curr = rnd(min(prev - 1, MAXELEMENT / (i + 1)), prev - 1);
    inp << curr << ' ';
    prev = curr;
  }
  inp << rnd(min(prev + 1, MAXELEMENT / (2)), MAXELEMENT / (2)) << ' ';
  // 2 elements
  // inp << 2 << '\n';
  // inp << 6969696 << ' ' << 696969696;
}


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i <= testNum; i++) {
    gentest(i);
  }
}

