#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

signed main() {
    FAST;
    MULTI {
        int n, k; cin >> n >> k;
        int a[n + 1];
        int hot[k + 1], cold[k + 1];
        for(int i = 1; i <= n; i++) {
            a[i] = nxt();
        }
        for(int i = 1; i <= k; i++) {
            cold[i] = nxt();
        }
        for(int i = 1; i <= k; i++) {
            hot[i] = nxt();
        }
        int res = 0;
        map<int, int> f;
        res += cold[a[1]];
        f[a[1]]++;
        map<int, int> minHot;
        map<int, int> minCold;
        minHot[a[1]] = hot[a[1]];
        minCold[a[1]] = cold[a[1]];
        for(int i = 2; i <= n; i++) {
            if(f[a[i]]) {
                minHot[a[i]] = min(hot[a[i]], minHot[a[i]]);
               // cout << minHot[a[i]] << endl;
                res += minHot[a[i]];
                f[a[i]];
            }
            else {
                //minCold[a[i]] = min(cold[a[i]], minCold[a[i]]);
                res += cold[a[i]];
               // cout << cold[a[i]];
                minHot[a[i]] = hot[a[i]];
                f[a[i]]++;
            }
        }
        cout << res << endl;
    }
}

