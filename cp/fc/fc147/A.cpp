/**
* File              : A.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 21.05.2023
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

int nxt() {int n; cin >> n; return n;}

int com(int n, int r) {
  double res = 1;
  for(int i = 1; i <= r; i++) {
    res = res * (n - r + i) / i;
  }
  return (int) res;
}

signed main() {
  FAST;
  int n, t; cin >> n >> t;
  vector<int> cntOdd(n + 1, 0);
  vector<int> cntEven(n + 1, 0); 
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(a[i] & 1) {
      cntOdd[i] = cntOdd[i - 1] + 1;
      cntEven[i] = cntEven[i - 1];
    }
    else {
      cntEven[i] = cntEven[i - 1] + 1;
      cntOdd[i] = cntOdd[i - 1];
    }
  }
  while(t--) {
    int l, r; cin >> l >> r;
    int totalEven = cntEven[r] - cntEven[l - 1];
    int totalOdd = cntOdd[r] - cntOdd[l - 1];
//    dbg(totalEven, totalOdd);
//    dbg(com(totalOdd, 2) * totalEven + com(totalEven, 3));
    cout << com(totalOdd, 2) * totalEven + com(totalEven, 3) << endl;
  }
}

