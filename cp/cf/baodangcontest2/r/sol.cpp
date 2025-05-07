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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

template <class T, class U = null_type, class cmp = less<T>>
using ordered_set = tree<T, U, cmp, rb_tree_tag,tree_order_statistics_node_update>;
#define int long long

const int D = (int) 1e7 + 5;

// Computing smallest prime factor as sieve in O(nloglogn)
// Largest prime factor can be computed by removing (a[j] == 0) condition
vector<int> spf(int n) {
  n++;
  vector<int> a(n);
  a[1] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i] == 0) {
      a[i]  = i;
      for (int j = 2 * i; j < n; j += i) {
        if (a[j] == 0) a[j] = i;
      }
    }
  }
  return a;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  int m[n], d[n - 1];
  for(int i = 0; i < n; i++) {
    cin >> m[i];
  }
  for(int i = 0; i < n - 1; i++) {
    cin >> d[i];
  }
  auto minPrime = spf(D);
  auto signalNumber = [&] (int num) -> bool {
    while(num > 1) {
      int p = minPrime[num], cnt = 0;
      while(num % p == 0) {
        cnt++;
        num /= p;
        if(cnt > 1)
          return false;
      }
    }
    return true;
  };
  vector<int> ans(n);
  for(int i = 0; i < n; i++) {
    ordered_set<int> os;
    //left 
    {
      int dis = 0;
      for(int l = i; l > 0; l--) {
        dis += d[l - 1];
        if(signalNumber(dis)) {
          os.insert(m[l - 1]);
        }
      }
    }
    //right
    {
      int dis = 0;
      for(int r = i; r < n - 1; r++) {
        dis += d[r];
        if(signalNumber(dis)) {
          ans[i] += os.order_of_key(m[r + 1]);
        }
      }
    }
  }
  for(int i : ans) {
    cout << i << ' ';
  }
}

