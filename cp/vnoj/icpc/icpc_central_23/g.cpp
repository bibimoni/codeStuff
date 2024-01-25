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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

void grundy_functions() {
  int N = 1000;
  vector<int> g(N + 11);
  g[0] = 0;
  for(int i = 1; i <= N; i++) {
    int cnt[10055];
    memset(cnt, 0, sizeof cnt);
    for(int j = 0; j < i; j++) cnt[g[j]] = 1;
    for(int j = 0; j * 2 < i; j++) cnt[g[j] ^ g[i - j]] = 1;
    while(cnt[g[i]]) g[i]++;
  }
  dbg(g);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  grundy_functions();
  /*
  int n; cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(x % 4 == 0) x--;
    else if(x % 4 == 3) x++;
    sum ^= x;
  }
  cout << (sum == 0 ? "Bob" : "Alice");
  */
}



