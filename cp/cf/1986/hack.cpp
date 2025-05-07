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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int t = 2;
  const int X = 107897;
  vector<int> p;
  for (int i = 1; i <= 1e5; i += 4) {
    if (i * X > (int) 1e9) {
      p.push_back(p.back());
    } else {
      p.push_back(i * X);
    }
  }
  cout << t << '\n';
  cout << p.size() << ' ' << (int) 1e9 << '\n';
  for(int i = 0; i < p.size(); i++) {
    cout << p[i] << " \n"[i == p.size() - 1];
  }
  cout << p.size() << ' ' << (int) 1e9 << '\n';
  for(int i = 0; i < p.size(); i++) {
    cout << p[i] << " \n"[i == p.size() - 1];
  }
}

