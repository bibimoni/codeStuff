/**
 * File              : E.cpp
 * Author            : distiled
 * Date              : 29.07.2023
 * Last Modified Date: 29.07.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}
int n, x;
vector<int> factors;
int ans = 0;

signed main() {
    TLE;
    cin >> n >> x;
    for(int i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }
    if(x != 1) factors.push_back(x);
    if(factors.size() < n) {
      cout << 1; return 0; 
    }
    //for(auto i : factors) cout << i << ' ';
    vector<int> tmp(n, 1);
    int k = 0;
    for (int i = 0; i < factors.size(); i++) {
      tmp[k] *= factors[i];
      k = (k + 1) % n;
    }
    int ans = tmp[0];
    for(int i = 1; i < n; i++) {
      ans = __gcd(ans, tmp[i]);
    }
    cout << ans;
}

