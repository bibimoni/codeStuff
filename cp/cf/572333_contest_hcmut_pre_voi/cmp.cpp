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

const string NAME = "b";

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  const int N = 100;
  for (int tt = 0; tt < N; tt++) {
    system(("./" + NAME + "__Generator").c_str());
    
    system(("./" + NAME).c_str());
    system(("./" + NAME + "__Good").c_str());

    if (system(("diff " + NAME + ".out " + NAME + "__Good.out").c_str()) != 0) {
      cout << "Test " << tt << " WRONG!\n";
      return 0;
    }
    cout << "Test " << tt << " CORRECT!\n";
}

