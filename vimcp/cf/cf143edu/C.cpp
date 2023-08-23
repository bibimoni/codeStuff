#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

void solve() {
    int n = nxt();
    int ans[n], a[n], b[n], pref[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ans[0] = min(a[0], b[0]);
    int sum = (a[0] - b[0] < 0) ? 0 : a[0] - b[0]; 
    for(int i = 1; i < n; i++) {
        int diff = (a[i] - b[i] < 0) ? 0 : a[i] - b[i];
        //cout << sum << ' ' << diff << endl;
        ans[i] = min(a[i], b[i]) + min(b[i], sum);
        sum += diff;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

signed main() {
    FAST;
    MULTI {
        solve();
    }
}
/*
4
3
10 20 15
9 8 6
1
5
7
4
13 8 5 4
3 4 2 1
3
1000000000 1000000000 1000000000
1 1 1000000000
 */
/* 
 9 9 12
5
3 8 6 4
1 2 2999999997
*/

