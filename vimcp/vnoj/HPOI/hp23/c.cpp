/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long

const int N = (int) 2e7 + 5;
int pref[N] = {};
bool isPrime[N] = {};

void sieve() {
  memset(isPrime, true, sizeof isPrime);
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i * i < N; i++) 
    if(isPrime[i]) 
      for(int j = i * i; j < N; j += i)
        isPrime[j] = false;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  sieve();
  int n, m; cin >> n >> m;
  for(int i = 1, x; i <= n; i++) {
    cin >> x;
    pref[i] = pref[i - 1] + x;
  }
  while(m--) {
    int l, r; cin >> l >> r;
    int sum = pref[r] - pref[l - 1];
    cout << (sum <= 1 ? 0 : (isPrime[sum])) << '\n';
  }
}

