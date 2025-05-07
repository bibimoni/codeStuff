/**
 * Author: distiled
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<list>
using namespace std;

#include "testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char * argv[]) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerGen(argc, argv, 1);
  int tt = opt<int>("tt");
  // auto n_vec = rnd.partition(tt, N);
  int MX = opt<int>("N");
  println(tt);
  for (int testcase = 0; testcase < tt; testcase++) {
    int n = rnd.next(1, MX);
    string s;
    if (rnd.next(2)) {
      s = "BKAC";
    } else {
      s = "GDSC";
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end());
    string tc = string(n, 'A');
    for (int i = 0; i < s.size(); i++) {
      tc[p[i]] = s[i];
    }
    for (int i = s.size(); i < n; i++) {
      tc[p[i]] = char(rnd.next(26) + 'A');
    }
    println(tc);
  }
}
