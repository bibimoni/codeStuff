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
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;
        map<char, int> f1, f2;
        for(int i = 0; i < n; i++) {
            f1[s[i]]++;
            f2[t[i]]++;
        }
        bool check = false;
        for(char i = 'a'; i <= 'z'; i++) {
            if(f1[i] != f2[i]) {
                check = true;
                break;
            }
        }
        bool mark[n] = {false};
        for(int i = 0; i < n; i++) {
            if(i + k < n || mark[i]) {
                mark[i] = true;
                if(i + k < n) mark[i + k] = true;
                continue;
            }
            if(s[i] != t[i]) {
                check = true;
                break;
            }
        }
        if(check) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}

