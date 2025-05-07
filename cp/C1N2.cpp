/**
 * File              : C1N2.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 22.09.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define sz(x)         (int) x.size()
#define MOD           1000000007
#define endl          '\n'
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}
map<int, bool> f1;
int b;
/*
 * tinh so buoc it nhat
 * state = true thi nhan doi a, state = false thi a++
 * chi co 2 truong hop la state = true hoac state = false luc chay ham calc 
*/
int calc(int a, bool state) {
  int cnt = 0;
  f1 = map<int, bool>(); // reset map 
  while(a <= b) {
    if(f1[a]) break; //neu f[a] = true chung to ham` da lap lai -> break vi khong co y nghia
    f1[a] = true;
    if(state) {
      a *= 2; state = false;
    }
    else {
      a++; state = true;
    }
    //neu chia het cho 3 thi chia
    if(a <= b && a % 3 == 0) a /= 3;  
    cnt++;
  }
  //neu break vong while nhung a <= b
  if(a <= b) return INT_MAX;
  return cnt;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("C1N2.INP", "r", stdin);
  freopen("C1N2.OUT", "w", stdout);
  int a; cin >> a >> b;
  int cnt = 0, ans = min(calc(a, true), calc(a, false));
  if(ans == INT_MAX) cout << -1;
  else cout << ans;
}

