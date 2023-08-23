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
    int n, q, k;
    cin >> n >> q >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 1e9, r = 0;
    while(q--) {
        int l = nxt();
        int r = nxt();
        sort(a + l, a + r + 1);
        //for(auto &i : a) cout << i << ' ';
        //cout << endl;
    }
    cout << a[k];

}

