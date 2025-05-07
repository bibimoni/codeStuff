/**
 * File              : vpc23_a.cpp
 * Author            : distiled
 * Date              : 02.08.2023
 * Last Modified Date: 04.08.2023
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

signed main() {
    TLE;
    int n, m; cin >> n >> m;
    char a[n + 1][m + 1];
    pair<int, int> res; bool check = false;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(!check && j >= 3 && a[i][j] == '.' && a[i][j - 1] == '.' && a[i][j - 2] == '.') {
                res = {i, j - 2};
                check = true;
            } 
        }
    cout << res.first << ' ' << res.second;
}

