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
        string s1, s2; cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        string s = "";
        int i, j;
        if(s1 == s2) {
            cout << "YES" << endl << s1 << endl;
            continue;
        }
        if(s1[0] == s2[0] or s1[n - 1] == s2[m - 1]) {
            cout << "YES" << endl;
            if(s1[0] == s2[0]) cout << s1[0] << '*' << endl;
            else if(s1[n - 1] == s2[m - 1]) cout << '*' << s1[n - 1] << endl;
            continue;
        }
        bool check= false;
        for(i = 0; i < n - 1; i++) {
            string temp = "";
            int size = 0;
            if(check) break;
            for(j = 0; j < m - 1; j++) {
                if(s1[i] == s2[j] and s1[i + 1] == s2[j + 1]) {
                    cout << "YES" << endl;
                    cout << '*' << s1[i] << s1[i + 1] << '*' << endl;
                    check = true;
                    break;
                }
            }
        }
        if(!check) cout << "NO" << endl;
    }
}

