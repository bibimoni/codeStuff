/**
 * https://ntucoder.net/Problem/Details/3382
 * File              : sumarrWithFedwick.cpp
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
#define MAXN (int) 1e6 + 5
int nxt() {int n; cin >> n; return n;}

int bit[MAXN], a[MAXN] = {0};
int n, q;

void update(int i, int v) {
  int idx = i + 1;
  while(idx < MAXN) {
    bit[idx] += v;
    idx += (idx & (-idx));
  }
}

int get(int i) {
  int idx = i + 1, ans = 0;
  while(idx > 0) {
    ans += bit[idx];
    idx -= ((-idx) & idx);
  }
  return ans;
}

signed main() {
  FAST;
  cin >> n >> q;
  memset(bit, 0, MAXN);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    update(i, a[i]);
  }
  while(q--) {
    char type; int a, b;
    cin >> type >> a >> b;
    if(type == 'S') {
      if(a == 0) {
        cout << get(b);
      }
      else {
        cout << get(b) - get(a - 1);
      }
      cout << endl;
    }
    else if(type == 'U') {
      update(a, b);
    }
    else {
      update(a, -b);
    }
  }
}

