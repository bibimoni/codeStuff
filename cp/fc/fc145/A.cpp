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
//    MULTI {
    	int n = nxt();
    	int a[n]; cin >> a[0];
    	bool check = false;
    	int temp = -1;
    	int sum = a[0];
        if(n == 1) {
            cout << -a[0] << endl;
            return 0;
        }
    	bool checkOpp = false;
    	bool checkNeg = false;
    	for(int i = 1; i < n; i++) {
    		a[i] = nxt();
    		sum += a[i];
    		if(a[i] == -1 && a[i - 1] == -1) {
    			check = true;
    		}    		
    		if(a[i] == 1 && a[i - 1] == 1) {
    			checkNeg = true;
    		}
    		if((a[i] == 1 && a[i - 1] == -1) ||
    			(a[i] == -1 && a[i - 1] == 1)) {
    			checkOpp = true;
    		}
    	}
        if(check) {
            cout << sum + 4 << endl;
        //    return 0;
        }
        else if(checkOpp) {
            cout << sum << endl;
        }
        else {
            cout << sum - 4 << endl;
        }
//    }
}
