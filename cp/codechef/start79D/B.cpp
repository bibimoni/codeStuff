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
        double a = nxt(), b = nxt();
        int A =(int) round(100 * (100 - a)), B =(int) round( 200 * (100 - b));     
        cout << A << ' ' << B << endl;
        if(A > B) {
            cout << "SECOND" << endl;
        }
        else if((int)B >(int) A) {
            cout << "FIRST" << endl;
        }
        else cout << "BOTH" << endl;
    }
}

