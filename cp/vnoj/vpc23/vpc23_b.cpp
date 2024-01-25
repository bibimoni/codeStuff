/**
 * File              : vpc23_b.cpp
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
    MULTI {
        int c, m, n; cin >> c >> m >> n;
        vector<pair<int, int>> pos;
        for(int i = 0; i < m; i++) {
            pos.push_back({nxt(), 0});
        }
        for(int i = 0; i < n; i++) {
            pos.push_back({nxt(), nxt()});
        }
        sort(all(pos));
        int curr = c, ans = 0;
        for(auto [p, q] : pos) {
            if(q == 0) {
                curr = c;
            }
            else {
                if(curr >= q) ans += q, curr -= q;
            }
        }
        cout << ans << endl;
    }
}

