/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 30.06.2023
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
  int n, m; cin >> m >> n;
  int mi[n], ball[n], tired[n];
  for(int i = 0; i < n; i++) {
    cin >> mi[i] >> ball[i] >> tired[i];
  }
  int l = 0, r = 1e9;
  int res = 0;
  vector<int> ret;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int totalBall = 0;
    vector<int> temp;
    for(int i = 0; i < n; i++) {
      int ans = 0;
      ans = ball[i] * (mid / (mi[i] * ball[i] + tired[i]));
      int rem = mid % (mi[i] * ball[i] + tired[i]);
      if(rem >= (mi[i] * ball[i])) ans += ball[i];
      else res += rem / mi[i];
      temp.push_back(ans);
      totalBall += ans;
    }
    dbg(totalBall, mid);
    if(totalBall >= m) {
      r = mid - 1;
      res = mid;
      ret = temp;
    }
    else {
      l = mid + 1;
    }
  }
  cout << res << endl;
  for(int i : ret) {

  }
}

