// time-limit: 3000
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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  string ans[n];
  for(int i = 0; i < n; i++) {
    string t; cin >> t;
    ans[i] = t;
  }
  sort(ans, ans + n, [&] (string a, string b) {
    string concat1 = a + b, concat2 = b + a;
    for(int i = 0; i < a.size() + b.size(); i++) {
      if(concat1[i] !=  concat2[i])
      return concat1[i] > concat2[i];
    }
    return concat1 > concat2;
  });
  for(string i : ans) cout << i;
}


