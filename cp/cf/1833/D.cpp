/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 20.05.2023
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

int nxt() {int n; cin >> n; return n;}

signed main() {
  FAST;
  MULTI {
    int n; cin >> n;
    int a[n];
    int posMax = 0, currMax = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(i >= 1 && currMax < a[i]) {
        currMax = a[i];
        posMax = i;
      }
    }
    if(n == 1) {
      cout << a[0] << endl;
      continue;
    }
    if(posMax == n - 1) {
      if(a[0] > a[posMax - 1]) {
        cout << a[posMax] << ' ';
        for(int i = 0; i < posMax; i++) {
          cout << a[i] << ' ';
        }
        cout << endl;
        continue;
      }
    }
    int l = posMax - 1;
    posMax--;
    int tempMax = 0;
    if(posMax == 0) {
      for(int i = posMax + 1; i < n; i ++) {
        cout << a[i] << ' ';
      }
      cout << a[0];
      continue;
    }
    if(a[posMax] > a[0]) {
      
    }
    dbg(posMax, l);
    for(int i = posMax + 1; i < n; i++) {
      cout << a[i] << ' ';
    }
    for(int i = posMax; i >= l; i--) {
      cout << a[i] << ' ';
    }
    for(int i = 0; i < l; i++) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
}
