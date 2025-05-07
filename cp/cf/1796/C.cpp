#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

int closestNumber(int n, int m) {
    int q = n / m;
    int n1 = m * q;
//    int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1));
    return n1; 
    
}

signed main() {
    FAST;
    MULTI {
        int x, y; cin >> x >> y;
        int res = 0;
        for(int i = x; i <= y; i++) {
            int temp = closestNumber(y, i);
            if(!temp) continue;
            if(temp == i || temp % i != 0) continue;
            res += ((temp / i) - 1) % mod;
            //cout << res << ' ' << i << ' ' << temp << endl;
        }
        cout << floor( log(y) / log(x) )<< ' ' << res << endl;
    }
}

