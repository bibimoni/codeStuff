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
        int x = nxt();
        if(x & 1) {
            cout << -1 << endl; continue;
        }
        int a = x >> 1;
        int b = x >> 1;
        if(a & x) {
            cout << -1 << endl;  continue;
        }
        else cout << a + x << ' ' << b << endl; 
    }

}

