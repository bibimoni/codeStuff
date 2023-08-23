#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

int calcBricks(int amount, int height) {
    if(height < 0) return 0;
    int total = amount * (amount + 1) / 2;
    //cout << total << endl;
    height -= amount;
    if(height < 0) {
        height = -height;
        total -= height * (height + 1) / 2;
    }
    else {
        total += height;
    }
    return total;
}

signed main() {
    FAST;
    //cout << calcBricks(3, 0);
    int n, h; cin >> n >> h;
    int a[n];
    for(int i = 0; i < n; i++) {
        a[i] = nxt();
    }
    int cnt = 1;
    int res = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i + 1] - a[i] == 1) {
            cnt++;
        }
        else {
            res += calcBricks(cnt, h);
            cnt = 1;
        }
        cout << res << endl;
    }
    //if(cnt != 0) res += calcBricks(cnt, h);
    cout << res;
}

