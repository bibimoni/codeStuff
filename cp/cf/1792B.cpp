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
        int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
        if(a1 == 0 && a1 + a2 + a3 + a4 != 0) {
            cout << 1 << endl;
            continue;
        }
        int cnt = a1;
//        cout << cnt << endl;
        cnt += min(a2, a3) * 2;
//        cout << cnt << endl;
        int temp = max(a2, a3) - min(a2, a3);
        cnt += (a1 >= temp) ? temp : a1 + 1;
        a1 -= temp;
        if(a1 < 0) {
            cout << cnt << endl;
        }
        else {
            if(a4 > a1) cnt += a1 + 1;
            else cnt += a4;
            cout << cnt << endl;
        }
    }
}


