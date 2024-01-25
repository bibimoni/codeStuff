#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

void solve() {
   int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int countDup = 0;
    bool check = true;
    for(int i = 0; i < n - 1; i++) {
        if(countDup >= 2) check = false; 
        if(a[i] == a[i + 1]) countDup++;
    }
    if(a[n - 1] == b[m - 1]) countDup++;
    for(int i = m - 1; i > 0; i--) {
        if(countDup >= 2) check = false;
        if(b[i] == b[i - 1]) countDup++;
    }
    //cout << countDup << endl;
    if(countDup >= 2) check = false;
    if(check) cout << "YES";
    else cout << "NO";
    cout << endl;
        
}

signed main() {
    FAST;
    MULTI {
        solve();
    }    
}

