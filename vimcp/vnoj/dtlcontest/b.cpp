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
#define all(x)         x.begin(), x.end()

const int N = (int) 2e6 + 5;
vector<int> primes;
vector<bool> isPrime(N, true);
int pre[N];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 2; i * i < N; i++) {
    if(isPrime[i]) {
      for(int j = i * i; j < N; j += i) {
        isPrime[j] = false;
      }
    }
  }
  for(int i = 2; i < N; i++) pre[i] = pre[i - 1] + isPrime[i];
  int tt;
  cin >> tt;
  auto count = [&] (int l, int r) {
    return pre[r] - pre[l - 1];
  };
  while(tt--) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int countA = count(a, c), countB = count(b, d);
    int l = max(a, b), r = min(c, d);
    int cnt = ((c < d || d < a) ? 0 : count(l, r));
    dbg(countA, countB, cnt, l, r);
    cout << countA * countB - cnt << '\n';
  }
}

