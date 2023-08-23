/**
 * https://ntucoder.net/Problem/Details/2246
 * File              : chiahet.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 19.05.2023
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
#define mod 21
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

int getlen(int num) {
  int cnt = 0;
  while(num != 0) {
    cnt++;
    num /= 10;
  }
  return cnt;
}

signed main() {
  FAST;
  int n; cin >> n;
  if(n < 2) {
    cout << -1;
    return 0;
  }
  if(n == 2) {
    cout << mod;
    return 0;
  }
  int lastDigitRemainder = 1;
  int base = 10;
  int powr = n - 1;
  while(powr > 0) {
    if(powr & 1) {
      lastDigitRemainder = (lastDigitRemainder * base) % mod;
    }
    base = (base * base) % mod;
    powr >>= 1;
  }
  lastDigitRemainder %= mod;
  int lastDigit = mod - lastDigitRemainder;
  cout << 1;
  for(int i = 2; i <= n - getlen(lastDigit); i++) {
    cout << 0;
  }
  cout << lastDigit;
}

