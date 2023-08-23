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
        char tmp[n]; cin >> tmp;
        sort(tmp, tmp + n);
        int cost = 0;
        char mid = tmp[n >> 1];
        for(int i = 0; i < n; i++) {
            cost += (abs(tmp[i] - mid));
        }
        cout << cost << endl;
        
    }
}

