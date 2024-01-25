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
    	int ans = 0;
    	int a, b, m, n;
    	cin >> a >> b >> n >> m;
    	if(n < m) {
    		a > b ? cout << n * b : cout << n * a; 
            cout << endl;
    		continue;
        }
    	if(a * m <= (m + 1) * b) {
    		int k = n / (m + 1); //first day buy k kilos
            ans += k * m * a;
    		int daysLeft = k == 0 ? n : n % n;     
    		ans += a > b ? b * daysLeft : a * daysLeft ;
            cout << ans << endl;
    	}
    	else {
    		  cout << b * n << endl;
    	}
    }
}
