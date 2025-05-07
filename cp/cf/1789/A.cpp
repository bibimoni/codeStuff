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
        bool check = false;
        int minGCD = 1e9;
        for(int i = 0; i < n; i++) a[i] = nxt();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                minGCD = min(minGCD, __gcd(a[i], a[j]));
            }
        }
        if(minGCD <= 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

