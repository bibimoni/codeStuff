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
        int X, Y; cin >> X >> Y;
        if(X == 1 or X < Y or (X == Y && !(X & 1))) {
            cout << "CHEFINA" << endl;
        }
        else if(Y == 1 or X > Y or (X == Y && X & 1)){
            cout << "CHEF" << endl;
        }
    }
}

