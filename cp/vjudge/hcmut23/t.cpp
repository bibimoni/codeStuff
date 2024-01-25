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

int parent[10011];
void init(int n) {
  for(int i = 1; i < 10111; i++) parent[i] = i;
}

int findSet(int u) {
  return u == parent[u] ? u : parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
  u = findSet(u), v = findSet(v);
  if(u == v) return;
  parent[v] = u;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  init(10000);
  MULTI {
    int u, v, z; cin >> u >> v >> z;
    if(z == 1) {
      unionSet(u, v);
    }
    if(z == 2) {
      u = findSet(u), v = findSet(v);
      cout << (u == v) << endl;
    }
  }
}



