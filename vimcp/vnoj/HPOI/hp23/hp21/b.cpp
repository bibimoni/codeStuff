// time-limit: 3000
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

const int N = (int) 2e6 + 5;
bool isPrime[N];
int pref[N];

void sieve() {
  memset(isPrime, true, sizeof isPrime);
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i * i < N; i++)
    if(isPrime[i])
      for(int j = i * i; j < N; j += i)
        isPrime[j] = false;
}

bool prime(int num) {
  for(int i = 2; i * i <= num; i++)
    if(num % i == 0) return false;
  return true;
}

bool check(int num) {
  if((num > (int) 2e6 && !prime(num)) || (num <= (int) 2e6 && !isPrime[num])) {
    return false;
  }
  bool isGood = false;
  for(int j = 1; j <= 9; j += 2) {
    int t = num * 10 + j;
    if((t > (int) 2e6 && prime(t)) || (t <= (int) 2e6 && isPrime[t])) {
      isGood = true;
      break;
    }
  }
  if(!isGood) {
    return false;
  }
  if(num < 10) {
    return true;
  }
  isGood = true;
  vector<int> extract;
  int tmp = num; tmp /= 10;
  while(tmp) {
    extract.push_back(tmp % 10);
    tmp /= 10;
  }
  for(int i = 0; i < (int) extract.size(); i++) {
    int num = 0;
    for(int j = (int) extract.size() - 1; j >= i; j--)
      num = num * 10 + extract[j];
    if((num > (int) 2e6 && !prime(num)) || (num <= (int) 2e6 && !isPrime[num])) {
      isGood = false;
      break;
    }
  }
  return isGood;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  sieve();
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    bool isGood = check(x);
    pref[i] = pref[i - 1] + (int) isGood;
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int u, v; cin >> u >> v;
    cout << pref[v] - pref[u - 1] << '\n';
  }
}


