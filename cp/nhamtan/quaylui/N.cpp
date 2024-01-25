/**
 * File              : N.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 16.07.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}void __print(long x) {cerr << x;}void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");}template<typename T, typename V>void __print(const pair<T, V> &x);template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}template<typename T, typename V>void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}void _print() {cerr << "]\n";}template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...)     cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

int n, x;
int ans = 0;
char toChar(int x) {
  return x + '0';
}

int toNum(char x) {
  return x - '0';
}

void compute(string t) {
  string curr = "";
  dbg(t);
  for(int i = 0; i < sz(t); i++) {
    if(t[i] == '*') {
      int tmp = curr[sz(curr) - 1];
      curr.pop_back();
      curr += toChar(toNum(tmp) * toNum(t[i + 1]));
    }
    else if(t[i] == '/') {
      int tmp = curr[sz(curr) - 1];
      curr.pop_back();
      curr += toChar(((int) toNum(tmp) / toNum(t[i + 1])));
    }
    else {
      curr += t[i];
    }
  }
  dbg(curr);
  int res = toNum(curr[0]);
  for(int i = 0; i < sz(curr) - 1; i++) {
    if(curr[i] == '+') {
      res = res + toNum(curr[i + 1]);
    }
    else if(curr[i] == '-') {
      res = res - toNum(curr[i + 1]);
    }
  }
  //dbg(res);
  if(res == x) ans++;
}

void Try(string pre, int i) {
  if(i == n + 1) {
    compute(pre);
    return;
  }
  for(char op : {'+', '-', '*', '/'}) {
    for(int j = 1; j <= 9; j++) {
      if(op == '+') {
        Try(pre + "+" + toChar(j), i + 1);
      }
      if(op == '-') {
        Try(pre + "-" + toChar(j), i + 1);
      }
      if(op == '*') {
        Try(pre + "*" + toChar(j), i + 1);
      }
      if(op == '/') {
        Try(pre + "/" + toChar(j), i + 1);
      }
    }
  }
}

signed main() {
  TLE;
  //cin >> n >> x;
  //for(int i = 1; i <= 9; i++) {
  //  string tmp(1, toChar(i));
  //  Try(tmp, 1);
  //}
  //cout << ans;
  compute("3+7/9+1-1*3/7-1");
}

