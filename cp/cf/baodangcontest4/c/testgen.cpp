/**
 * Author: distiled
 */
#include<iostream>
using namespace std;
#include "../testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char * argv[]) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerGen(argc, argv, 1);
  int N = opt<int>("N");
  int t = opt<int>("t");
  auto gen = [&] (int n) -> vector<int> {
    set<pair<int, int>> st;
    vector<int> d(n);
    for(int i = 1; i <= n; i++) {
      st.insert({i, i});
    }

    int edges = rnd.next(0, n * (n - 1) / 2);
    for(int i = 0; i < edges; i++) {
      int u = rnd.next(0, n - 2);
      int v = rnd.next(u + 1, n - 1);
      while(st.find({u, v}) != st.end()) {
        u = rnd.next(0, n - 2);
        v = rnd.next(u + 1, n - 1);
      } 
      st.insert({u, v});
      d[u]++;
      d[v]++;
    }
    return d;
  };
  cout << t << '\n';
  for(int i = 0; i < t; i++) {
    int n = N / t;
    cout << n << '\n';
    bool ok = rnd.next(0, 1);
    vector<int> d(n);
    if(ok && N <= 200) {
      d = gen(n);
    }
    else {
      for(int i = 0; i < n; i++) {
        d[i] = rnd.next(1, n - 1);
      }
      shuffle(d.begin(), d.end());
    }
    for(int i = 0; i < d.size(); i++) {
      cout << d[i] << " \n"[i == d.size() - 1];
    }
  }
}

