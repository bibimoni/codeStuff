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
        string s; cin >> s;
        map<char, int> f;
        int res = 0;
        for(auto i : s) {
            if(i == tolower(i)) {
                f[i]++;
            }
            else {
                f[i]++;
            }
        }
        for(char i = 'a'; i <= 'z'; i++) {
            int val1 = f[i];
            int val2 = f[toupper(i)];
            res += min(val1, val2);
            int remain = max(val1, val2) - min(val1, val2);
            remain -= remain % 2;
            //cout << val1 << ' ' << val2 << endl;
            if(remain > 1) {
                if(k > (remain / 2)) {
                    res += (remain / 2);
                    k -= remain / 2;
                }
                else {
                    res += k;
                    k = 0;
                }
            }
        }
        cout << res << endl;
    }
}

