/**
 * File              : zrlcm.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 16.06.2023
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

#define all(x) x.begin(), x.end();
#define int long long
#define mod 1000000007
#define endl '\n'
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)
#define INF (int) 1e8 + 9
#define MAXN (int) 1e6 + 9

int cntP = 0;
vector<int> minPrime(MAXN, 0);
unordered_map<int, int> maxMap;

int nxt() {int n; cin >> n; return n;}

int power(int a, int n) {
  int x = 1, y = a;
  while(n > 0) {
    if(n & 1) {
      x = (x * y) % mod;
    }
    y = (y * y) % mod;
    n >>= 1;
  }
  return x % mod;
}

void sieve() {
  minPrime[0] = minPrime[1] = 1;
  for(int i = 2; i * i < MAXN; i++) {
    if(minPrime[i] == 0) {
      minPrime[i] = i;
      for(int j = i * i; j < MAXN; j += i) {
        if(minPrime[j] == 0) {
          minPrime[j] = i;
        }
      }
    }
  }
  for(int i = 2; i < MAXN; i++) {
    if(minPrime[i] == 0) {
      minPrime[i] = i;
    }
  }
}

signed main() {
  TLE;
  sieve();
  int n; cin >> n;
  int k = 1;
  if(n == 1) {
    cout << 1; return 0;
  }
  for(int i = 2; i <= n; i++) {
    int num = i;
    unordered_map<int, int> temp;
    while(num != 1) {  
      int fac = minPrime[num];
      temp[fac]++;
      num /= fac;
    }
    for(auto it: temp) {
      dbg(it.first, it.second);
      maxMap[it.first] = max(maxMap[it.first], it.second);
    }
  }
  for(auto it: maxMap) {
    k = (k * power(it.first, it.second)) % mod;
  }
  cout << k;
  

}

