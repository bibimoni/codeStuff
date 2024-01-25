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
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        priority_queue<int> Q;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != 0) {
                Q.push(a[i]);
            }
            else {
                if(!Q.empty()) {
                    res += Q.top(); Q.pop();
                }
            }
        }
        cout << res << endl;;
    }
}

