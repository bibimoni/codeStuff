/**
 * File              : 812C.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 15.07.2023
 * Last Modified By  : distiled
 */
#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V> &x);
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifdef DEBUG
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define __lcm(a, b) (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define mod 1000000007
#define endl '\n'
#define TLE                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define MULTI                                                                  \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define INF (int)1e18
#define MAXN (int)1e6 + 5

int nxt() {
  int n;
  cin >> n;
  return n;
}

int a[MAXN], b[MAXN], n;

int calc(int k) {
  for (int i = 1; i <= n; i++) {
    b[i] = a[i] + i * k;
  }
  sort(b + 1, b + n + 1);
  int res = 0;
  for (int i = 1; i <= k; i++) {
    res += b[i];
  }
  return res;
}

signed main() {
  TLE;
  int s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n;
  int ans = 0, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int cost = calc(mid);
    if (cost > s) {
      r = mid - 1;
    } else {
      l = mid + 1;
      ans = mid;
      res = cost;
    }
  }
  cout << ans << ' ' << res;
}
