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
        int n, m; cin >> n >> m;
        map<int, int> f;
        vector<int> res(n, -1);
        int curr = n;
        for(int i = 1; i <= m; i++) {
            int x = nxt();
            if(!f[x]) {
                if(curr - 1 >= 0) res[curr - 1] = i; 
                curr--;
                f[x]++;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << res[i] << ' ';
        }
        cout << endl;
    }
}

