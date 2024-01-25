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
    int n, k; cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 1; j <= k; j++) {
            a[i] = a[i] * (2 * (i))
        }
    }
}