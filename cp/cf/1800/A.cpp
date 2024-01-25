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
        for(auto &x : s) x = tolower(x);
        bool check = false;
        string t;
        map<char, int> f;
        t += s[0];
        if(!(s[0] == 'm' || s[0] == 'e' || s[0] == 'o' || s[0] == 'w')) {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 1; i < n; i++) {
            if(!(s[i] == 'm' || s[i] == 'e' || s[i] == 'o' || s[i] == 'w')) {
                
                check = true;
                break;
            }
            if(s[i] != s[i - 1]) {
                t += s[i];
            }
                 
                 
             
        }
        //cout << t << endl;
        if(check || t.find("meow") == std::string::npos || t.size() > 4) {
            cout << "NO";
        }
        else cout << "YES";
        cout << endl;
   }
}


