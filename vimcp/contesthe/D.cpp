/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 13.07.2023
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

signed main() {
  TLE;
  int n, k; cin >> n >> k;
  vector<int> a(n);
  int pre[n], suf[n];   for(int i = 0; i < n; i++) cin >> a[i];
  int curr = 0, ans = -INF;
  for(int i = 0; i < n; i++) {
    curr = max(curr + a[i], a[i]);
    ans = max(curr, ans);
  }
  ans = max({ans, ans * k, 0ll});
  int st = 0, e = 0, s = 0;
  for(int i = 0; i < n; i++) {
    curr += a[i] * k;
    if(ans < curr) {
      ans = curr;
      st = s;
      e = i;
    }
    if(curr < 0) {
      curr = 0;
      s = i + 1;
    }
  }
  vector<int> c(all(a));
  int oldSum = 0, newSum = 0;
  for(int i = st; i <= e; i++) {
    oldSum += a[i];
    c.push_back(a[i]);
    a[i] *= k;
    newSum += a[i];
  }
  if(newSum < oldSum || k == 0) {
    a = vector<int>(all(c));
  }
  curr = 0; ans = -INF;
  for(int i = 0; i < n; i++) {
    curr = max(curr + a[i], a[i]);
    ans = max(ans, curr);
  }
  cout << ans;
}

