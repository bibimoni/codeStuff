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
    int n = nxt();
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    int res = 0;
    int curr = c[0];
    for(int i = 1; i < n; i++) {
        curr = max(curr, c[i]);
        int profit = curr - c[i];
        res = max(res, profit);
    }
    cout << res;
}

