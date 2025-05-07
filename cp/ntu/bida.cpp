/**
 * File              : bida.cpp
 * Author            : distiled
 * Date              : 06.06.2023
 * Last Modified Date: 06.06.2023
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
#define maxN (long long) 1e6 + 5
#define mod 1000000007
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

signed main() {
  fast
  int n, m, y, x, k; cin >> n >> m >> y >> x >> k;
  int dirY = 1, dirX = 1;
  while(k > 0) {
    //cerr << x << ' ' << y << ' ' << k << " dir: " << dirX << ' ' << dirY << endl;
    if(dirY == 1 && dirX == 1) {
      if(k <= min(n - y, m - x)) {
        x += k;
        y += k;
        break;
      }
      int ny = y + min(n - y, m - x);
      int nx = x + min(n - y, m - x);
      k -= min(n - y, m - x);
      y = ny; x = nx;
      dirY = -dirY;
    }
    else if(dirY == 1 && dirX == -1) {
      if(k <= min(x - 1, n - y)) {
        x -= k;
        y += k;
        break;
      }
      int ny = y + min(x - 1, n - y);
      int nx = x - min(x - 1, n - y);
      k -= min(x - 1, n - y);
      y = ny; x = nx;
      dirX = -dirX;
    }
    else if(dirY == -1 && dirX == -1) {
      if(k <= min(y - 1, x - 1)) {
        x -= k;
        y -= k;
        break;
      }
      int ny = y - min(y - 1, x - 1);
      int nx = x - min(y - 1, x - 1);
      k -= min(y - 1, x - 1);
      y = ny; x = nx;
      dirY = -dirY;
    }
    else if(dirY == -1 && dirX == 1) {
      if(k <= min(y - 1, m - x)) {
        x += k;
        y -= k;
        break;
      }
      int nx = x + min(y - 1, m - x);
      int ny = y - min(y - 1, m - x);
      k -= min(y - 1, m - x);
      y = ny; x = nx;
      dirX = -dirX;
    }
    dbg(y, x, dirX, dirY, k);
  }
  cout << y << ' ' << x;
}
