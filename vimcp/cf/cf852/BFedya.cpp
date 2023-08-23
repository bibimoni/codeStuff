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
		int a, b;
        cin >> a >> b;
        int n = 2 * (a - b); 
        int i = 0;
        int ans[n];
        for(int j = b; j <= a; j++) {
            ans[i++] = j;
        }            
        for(int j = a - 1; j > b; j--) {
            ans[i++] = j;
        }
        cout << n - (n == i - 1) << endl;
        for(int j = 0; j < i; j++) {
            cout << ans[j] << ' ';
        }
        cout << endl;
    }
}

