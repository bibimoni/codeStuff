/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 18.06.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end();
#define int long long
#define mod 1000000007
#define endl '\n'
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)
#define MAXN (int) 1e7 + 9

int cntP = 0;
vector<int> minPrime(MAXN, 0);
int temp1[MAXN] , temp2[MAXN];

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
  int n, m; cin >> n >> m;
  int ans = 1; 
  for(int i = 1; i <= n; i++) {
    int num = nxt();
    while(num != 1) {  
      int fac = minPrime[num];
      temp1[fac]++;
      num /= fac;
    }
  }
  for(int i = 1; i <= m; i++) {
    int num = nxt();
    while(num != 1) {  
      int fac = minPrime[num];
      temp2[fac]++;
      num /= fac;
    }
  }
  for (int i = 1 ; i < MAXN ; i++) {
    int powr = min(temp1[i], temp2[i]);
    if (powr > 0) {
        ans = (ans * power(i, powr)) % mod;
    }
  }
  cout << ans;
}

