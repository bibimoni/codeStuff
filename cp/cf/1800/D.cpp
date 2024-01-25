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
        string s; cin >> s;
        int res = n - 1;
        //cout << res << endl;
        for(int i = 0; i < n - 2; i++) {
            int cnt = 0;
            if(s[i] == s[i + 2]) res--;
            
            //cout << cnt << ' ' << res << endl;
        }
        cout << res << endl;
    }
}

