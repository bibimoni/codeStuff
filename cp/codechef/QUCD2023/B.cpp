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
        int tracker = 0;
        if(n == k) {
            for(int i = 1; i <= n; i++) cout << i << ' ';
            cout << endl;
            continue;
        }
        vector<vector<int>> subArray((n / k));
        int curr = 0;
        //cout << sum << endl;
        int j = 0;
        int state = 1;
        for(int i = 1; i <= n; i++) {
            subArray[j].push_back(i);
            //cout << j << endl;
            j += state;
            if(j == (n / k) - 1 || j == 0) {
                subArray[j].push_back(++i);
                state = -state;
            }
        }

        for(int i = 0; i < n / k; i++) {
            for(int j = 0; j < k; j++) {
                cout << subArray[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

