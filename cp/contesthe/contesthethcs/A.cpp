/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 30.07.2023
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

bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    if(a.second.first == b.second.first) 
        return a.second.second < b.second.second;
    return a.second.first > b.second.first;
} 

signed main() {
  TLE;
  map<int, pair<int, int>> f;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        auto [k, v] = f[x];
        if(k == 0 && v == 0) {
            k = 1; v = i;
            f[x] = {k, v};
        }
        else {
            k++;
            f[x] = {k, v};
        }
    }
    vector<pair<int, pair<int, int>>> A;
    for(auto it : f) {
        A.push_back(it);
    }
    sort(all(A), cmp);
    for(auto [v, k] : A) {
        for(int i = 0; i < k.first; i++) {
            cout << v << ' ';
        }
    }
}

