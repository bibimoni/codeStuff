/**
 * File              : C.cpp
 * Author            : distiled
 * Date              : 29.07.2023
 * Last Modified Date: 30.07.2023
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

int n, a[MAXN], ans = 0;

void recursion(int l, int r, int curr) {
    int lowest = INF;
    for(int i = l; i <= r; i++) 
        lowest = min(lowest, a[i]);
    ans += lowest - curr;
    for(int i = l; i <= r; i++) {
        if(a[i] != lowest) {
            int pos = i;
            while(i <= r and a[i] != lowest) {
                i++;
            }
            i--;
            recursion(pos, i, lowest);
        }
    }
}

signed main() {
    TLE;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    recursion(0, n - 1, 0);
    cout << ans;
}

