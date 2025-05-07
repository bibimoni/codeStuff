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
#define int int64_t

const int N = 48185;

vector<int> make_evils(int prime, int n) {
  vector<int> ret(n);
  for (int i = 0; i < n; i++) {
    ret[i] = (i + 1) * prime;
  }
  return ret;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n = N, m = N;
  vector<int> evils = make_evils(541, N);
  int q = 5e4;
  cout << n << ' ' << m << ' ' << q << '\n';
  for (int i = 0; i < evils.size(); i++) {
    cout << evils[i] << " \n"[i == evils.size() - 1];
  }
  for (int i = 0; i < evils.size(); i++) {
    cout << evils[i] << " \n"[i == evils.size() - 1];
  }
  for (int i = 0; i < min(q, (int)evils.size()); i++) {
    cout << evils[i] << "\n";
  }
}

