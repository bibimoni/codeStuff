/**
 * File              : coci20c3p4.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 27.06.2023
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
#define INF           (int) 1e9
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
  int n, m; cin >> n >> m;
  char a[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  //0 horizontal 1 vertical
  vector<int> prev( 1 << m, INF), curr(1 << m);
  prev[0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      //each state of a row
      for(int k = 0; k < (1 << m); k++) {
        //current bit is 1
       if(k & (1 << j)) {
         if(a[i][j] == '.') {
           curr[k] = INF;
         }
         else {
           //cell above using a horizontal line then add 1 cus we use vertical
           curr[k] = min(prev[k], prev[k ^ (1 << j)] + 1);
         }
       }
       else {
         //if left cell is 0
         curr[k] = min(prev[k], prev[k ^ (1 << j)]);
         //if left cell is 1 or current bit is the starter
         if(a[i][j] == '#' && ((j == 0) || (k & (1 << (j - 1))) || a[i][j - 1] == '.')) {
           curr[k]++;
         }
        }
      }
      prev = curr;
    }
  }
  cout << *min_element(prev.begin(), prev.end()) - 1;
}

