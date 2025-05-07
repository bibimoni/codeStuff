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
        int n = nxt();
        int a[n + 2];
        for(int i = 1; i <= n; i++) cin >> a[i];
        int cnt = 0;
        a[n + 1] = 1440;
        a[0] = 0;
        for(int i = 0; i <= n; i++) {
            if((a[i + 1] - a[i]) / 120.0 >= 1) {
                cnt += floor((a[i + 1] - a[i]) / 120.0);
            }
        }
        if(cnt >= 2) cout << "YES";
        else cout << "NO";
        cout << endl;
    }    
}

