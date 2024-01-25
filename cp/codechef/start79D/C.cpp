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
        vector<int> ans = vector<int>(n);
        int k = 0;
        for(int i = 1; i <= n; i+=2) {
            ans[k] = i;
            ans[n - k - 1] = i + 1;
            k++;
        }
        for(auto &i : ans) cout << i << ' ';
        cout << endl;
    }
}

