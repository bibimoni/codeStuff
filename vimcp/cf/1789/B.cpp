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
        string s; cin >> s;
        int j = 0,
            i = n - 1;
        int check = 0;
        //cerr << i << ' ' << j << endl;
        while(i > j) {
            if(s[i] != s[j]) {
                while(i < n && s[i] != s[j]) {
                    i--; j++;
                }
                //i++; j++;
                check++;
            }
            i--; j++;
            //cerr << i << ' ' << j << endl;
        }
        if(check > 1) {
            cout << "No";
        }
        else cout << "Yes";
        cout << endl;
    }
}

