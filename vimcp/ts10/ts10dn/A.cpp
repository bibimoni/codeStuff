/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 14.06.2023
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
#define MAXN (int) 2e3 + 5
#define MAXP (int) 200

int nxt() {int n; cin >> n; return n;}
 
vector<int> a(19); int n;
vector<bool> isPrime(MAXN, true);
vector<vector<vector<int>>> dp(20, vector<vector<int>>(MAXP, vector<int>(MAXN, -1)));
void sieve() {
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i * i < MAXN; i++) {
    if(isPrime[i]) {
      for(int j = i * i; j < MAXN; j += i) {
        isPrime[j] = false;
      }
    }
  }
}
 
// x = a[n - 1]a[n - 2]...a[0]
// digit i, limit with the currnumber, sum of current digit
int dfs(int i, bool limit, int sum, int sqrSum) {
  dbg(i);
  if(i < 0) {
    if(isPrime[sum] && isPrime[sqrSum]) return 1;
    else return 0;
  }
  if(!limit && dp[i][sum][sqrSum] >= 0) {
    return dp[i][sum][sqrSum];
  }
  int ret = 0;
  int maxD = (limit ? a[i] : 9);
  for(int c = 0; c <= maxD; c++) {
    bool limitM = limit && (c == maxD);
    ret += dfs(i - 1, limitM, sum + c, sqrSum + c * c);
  }
  if(!limit) dp[i][sum][sqrSum] = ret;
  return ret;
}
 
int G(int x) {
  a[0] = 0;
  n = 0;
  while(x > 0) {
    a[n] = x % 10;
    x /= 10;
    n++;
  }
  return dfs(n - 1, true, 0, 0);
}
 
signed main() {
  FAST;
  sieve();
  MULTI {
  int l, r; 
  cin >> l >> r;
  cout << G(r) - G(l - 1) << endl;
}
}
