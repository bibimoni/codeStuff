/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 18.06.2023
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
#define MAXN (int) 1e7 + 3

int nxtL[MAXN], nxtQ[MAXN], nxtD[MAXN];

signed main() {
  TLE;
  int n, k; cin >> n >> k;
  string s; cin >> s;
  deque<int> Ql, Qq, Qd;
  bool firstL = true, firstQ = true, firstD = true;
  int res = 1e9;
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == 'L') {
      Ql.push_back(i);
    }
    if(s[i] == 'Q') {
      Qq.push_back(i);
    }
    if(s[i] == 'D') {
      Qd.push_back(i);
    }
    if((int) Ql.size() == k + 1) {
      Ql.pop_front();
      firstL = false;
    }
    if((int) Qq.size() == k + 1) {
      Qq.pop_front();
      firstQ = false;
    }
    if((int) Qd.size() == k + 1) {
      Qd.pop_front();
      firstD = false;
    }    
    nxtL[i] = ((int) Ql.size() < k && firstL) ? -1 : Ql.front();
    nxtQ[i] = ((int) Qq.size() < k && firstQ) ? -1 : Qq.front();
    nxtD[i] = ((int) Qd.size() < k && firstD) ? -1 : Qd.front();
  }
//  for(int i = 0; i < n; i++) {
//    dbg(nxt[0][i], nxt[1][i], nxt[2][i]);
//  }
  for(int i = 0; i <= n - 3 * k; i++) {
    int nxt = nxtL[i];
    if(nxt >= 0 && nxt + 1 < n) {
      nxt = nxtQ[nxt]; 
    }
    else {
      continue;
    }
    if(nxt >= 0 && nxt + 1 < n) {
      nxt = nxtD[nxt];
    }
    else {
      continue;
    }
    if(nxt > 0) {
//      dbg(nxtL, i, nxtL - i + 1);
    res = min(res, (nxt - i + 1) - 3 * k);
//      dbg(res);
    }
  }
  if(res == 1e9) {
    cout << -1;
  }
  else {
    cout << res;
  }
}

