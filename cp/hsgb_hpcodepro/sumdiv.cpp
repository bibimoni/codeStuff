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
    int n, T; cin >> n >> T;
    int a[n];
    int maxVal = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }
    vector<int> minPrimes(maxVal + 1, 0);
    for(int i = 2; i <= maxVal; i += 2) {
        minPrimes[i] = 2;
    }
    for(int i = 3; i <= maxVal; i += 2) {
        if(minPrimes[i] == 0) {
            minPrimes[i] = i;
            for(int j = i * i; j<= maxVal; j += i) {
                if(minPrimes[j] == 0) {
                    minPrimes[j] = i;
                }
            }
        }
    }
    int pre[n + 1];
    pre[0] = 0;
    pre[1] = minPrimes[a[0]];
    for(int i = 2; i <= n; i++) {
        pre[i] = minPrimes[a[i - 1]] + pre[i - 1];
    }
    //for(auto &i: pre) cout << i << ' ';
    //cout << endl;
    while(T--) {
        int x, y; cin >> x >> y;
        int res = y - x + 1;
        res += (pre[y] - pre[x - 1]); 
        cout << res << endl;
    }
}
