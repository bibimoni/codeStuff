/**
 * File              : B.cpp
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

int ans = 0;
map<int, bool> f;
int getlength(int num) {
  int cnt = 0;
  while(num != 0) {
    cnt++;
    num /= 10;
  }
  return cnt;
}

int reverseNum(int num) {
  int temp = 0;
  while(num != 0) {
    temp = temp * 10 + num % 10;
    num /= 10;
  }
  return temp;
}

int numberInlenAtI(int l, int r, int i, int num, int len) {
  int firstHalf = 0;
  int secondHalf = 0;
  int maxSecondHalf = pow(10, i - 1) - 1;
  int maxFirstHalf = pow(10, len - (i + getlength(num) - 1));
  int cnt = 0;
  while(secondHalf <= maxSecondHalf) {
    int temp = secondHalf * pow(10, len - i + 1) + num * pow(10, len - (i + getlength(num) - 1)) + firstHalf;
    if(l <= temp and r >= temp) {
      dbg(temp, l, r, f[temp]);
      if(f[temp] == false) {
        f[temp] = true;
        cnt++;
      } 
    }
    firstHalf++;
    if(firstHalf >= maxFirstHalf) {
      secondHalf++;
      firstHalf = 0;
    }
  }
  return cnt;
}

int solveForlen(int l, int r, int len, int k) {
    int cnt = 0;
    for(int i = 1; i <= len - getlength(k) + 1; i++) {
      cnt += numberInlenAtI(l, r, i, k, len);
    }
    return cnt; 
}

signed main() {
  FAST;
  int k, l, r; cin >> k >> l >> r;
  int k1 = reverseNum(k);
  int len1 = getlength(l), len2 = getlength(r);
//  cout << solveForlen(1111, 6666, 4, 12);   
  int res = 0;
  for(int i = len1; i <= len2; i++) {
    res += solveForlen(l, r, i, k);
    res += solveForlen(l, r, i, k1);
  }
  cout << res;
}

