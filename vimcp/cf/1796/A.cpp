#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

string a = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFB";
signed main() {
    FAST;
    MULTI {
        int n = nxt(); string s; cin >> s;
        if(a.find(s) != std::string::npos) {
            cout << "yes";
        }
        else {
            cout << "no";
        }
        cout << endl;
    }
}

