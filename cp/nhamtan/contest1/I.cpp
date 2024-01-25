/**
 * File              : I.cpp
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
#define MAXM          (int) 1e6 + 5

template<typename T> struct RangeMinQuery {
  int N, _N;
  vector<T> dat;
  T initial;

  RangeMinQuery(int _N, T initial = INF) : _N(_N), initial(initial) {
    assert(_N > 0);
    N = 1;
    while (N < _N)
      N <<= 1;
    dat.assign(2 * N - 1, initial);
  }

  void update(int k, T val) {
    assert(0 <= k && k < _N);
    k += N - 1;
    dat[k] = val;

    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }

  // [a, b)
  T query(int a, int b) {
    assert(0 <= a && a <= b && b <= _N);
    return query(a, b, 0, 0, N);
  }

  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return initial;
    if (a <= l && r <= b) return dat[k];

    int mid = (l + r) / 2;
    return min(query(a, b, 2 * k + 1, l, mid),
               query(a, b, 2 * k + 2, mid, r));
  }
};

signed main() {
  TLE;

}

