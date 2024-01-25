/**
 * File              : L.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 09.10.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define makeUnique(x)  sort(all(x)); x.erase(unique(all(x)), x.end());
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
const int 
      MAXN = (int) 5e6 + 111, 
      INF = (int) 1e18, 
      MOD = (int) 998244353;
inline int nxt() { int n; cin >> n; return n; }
void add(int& a, const int& b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

vector<int> minPrime(MAXN, 0);
void sieve() {
  for(int i = 2; i * i < MAXN; i++) {
    if(!minPrime[i]) {
      for(int j = i * i; j < MAXN; j += i) {
        if(!minPrime[j]) minPrime[j] = i;
      }
    }
  }
  for(int i = 2; i < MAXN; i++) {
    if(!minPrime[i]) minPrime[i] = i;
  }
}

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  sieve();
  int a, b; cin >> a >> b;  
  int phiA = a, sum = 0;
  unordered_set<int> factors;
  int tmp = a;
  while(tmp > 1) {
    factors.insert(minPrime[tmp]);
    int p = minPrime[tmp];
    phiA -= phiA / p;
    while(tmp % p == 0) {
      tmp /= p;
    } 
  }
  for(int i = 1; i <= b; i++) {
    int phiMult = phiA * i;
    int tmp = i;
    while(tmp > 1) {
      int p = minPrime[tmp];
      if(!factors.count(p)) 
        phiMult -= phiMult / p;
      while(tmp % p == 0) {
        tmp /= p;
      }
    }
    //dbg(phiMult)
    add(sum, phiMult % MOD);
  }
  cout << (int) sum;
}

