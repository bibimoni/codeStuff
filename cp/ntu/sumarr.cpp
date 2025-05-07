/**
 * File              : sumarr.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 26.05.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)
#define MAXN (int) 2e6 + 10
int nxt() {int n; cin >> n; return n;}

int tree[MAXN * 4];
int n, a[MAXN];

void build(int node, int segL, int segR) {
  if(segL == segR) {
    tree[node] = a[segL];
  }
  else {
    int segMid = (segR + segL) / 2;
    build(node * 2, segL, segMid);
    build(node * 2 + 1, segMid + 1, segR);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
}

int sum(int node, int segL, int segR, int l, int r) {
  if(l > r) return 0;
  if(l <= segL && r >= segR) {
    return tree[node];
  }
  int segMid = (segR + segL) / 2;
  return sum(node * 2, segL, segMid, l, r) 
    +   sum(node * 2 + 1, segMid + 1, segR, l ,r);
}

void update(int node, int segL, int segR, int i, int v) {
  if(segL > i || segR < i) return;
  if(segR == segL) {
    tree[node] += v;
    return;
  }
  else {
    int segMid = (segR + segL) / 2;
    if(segMid < i) {
      update(node * 2 + 1, segMid + 1, segR, i, v);
    }
    else {
      update(node * 2, segL, segMid, i , v);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
}

signed main() {
  FAST;
  int q; cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(1, 0, n - 1);
  while(q--) {
    char type;
    int a, b; cin >> type >> a >> b;
    if(type == 'S') {
      cout << sum(1, 0, n - 1, a, b) << endl;
    }
    else if(type == 'U') {
      update(1, 0, n - 1, a, b);
    }
    else if(type == 'V') {
      update(1, 0, n - 1, a, -b);
    }
  }
}
