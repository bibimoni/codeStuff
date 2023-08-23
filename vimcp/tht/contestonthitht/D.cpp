/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 27.05.2023
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

int state = 0;
int n; 
string s;
int finish1 = 0;
int finish2 = 0;
int res = 1e9;

void printBin(int num) {
  string s = "";
  while(num > 0) {
    s += (num & 1) + '0';
    num >>= 1;
  }
//  reverse(s.begin(), s.end());
  cout << s << endl;
}

int getBitAtI(int i, int num) {
  return (num >> (i - 1)) & 1;
}

void changebit(int &num, int i) {
  num = (num ^ (1 << (i - 1)));
}

void Try(int step, int i, int state) {
  cout << step << ' '; printBin(state);
  if(state == finish1 || state == finish2) {
    res = min(step, res);
    return;
  }
  if(res < step || i == n) return;
  Try(step, i + 1, state);
  if(i <= n - 2) {
    int temp = state;
    changebit(temp, i);
    changebit(temp, i + 1);
    changebit(temp, i + 2);
    Try(step + 1, i + 1, temp);
  }
  if(i <= n - 1) {
    int temp = state;
    changebit(temp, i);
    changebit(temp, i + 1);
    Try(step + 1, i + 1, temp);
  }
};

signed main() {
  FAST;
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'A')
      state |= (1 << i);
  }
  finish2 = (1 << n) - 1;
  Try(0, 1, state);
  cout << res;
}

