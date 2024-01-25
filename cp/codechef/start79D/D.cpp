#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

unordered_map<int, int> f;

int SPF(int n) {
    if(!(n & 1)) return 2;
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            return i;
        }
    }
    return n;
}

signed main() {
    FAST;
    f[2] = 2;
    MULTI {
        int x, y; cin >> x >> y;
        int k = 0;
        while(x < y) {
            k++;
            if(!f[x]) {
                f[x] = SPF(x);
            }
            x += f[x];
        }
        cout << k << endl;
    }
}

