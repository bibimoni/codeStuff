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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k; cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i], a[i] += k;
  for(int i = 0, id; i < k; i++) cin >> id, a[--id]--;
  for(int i = 0; i < n; i++) cout << a[i] << ' ';
}

