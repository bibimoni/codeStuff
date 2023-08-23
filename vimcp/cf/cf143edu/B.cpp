#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

void solve() {
    int n, k; cin >> n >> k;
    map<int, pair<int, int>> freq;
    int kAppear = 0;
    int rMax = 0;
    int lMin = 51;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        lMin = min(lMin, l);
        rMax = max(rMax, r);
        if(l <= k && r >= k) kAppear++;
        for(int j = l; j <= r; j++) {
            if(j == k) continue;
            if(!(l <= k && r >= k)) {
                //count total segment doesnt have k
                freq[j].second++;
            }
            //increase the appearence of all value from l to r
            freq[j].first++;
        }
    }
    //cout << kAppear << endl;
    //cout << "range is: " << lMin << " -> " << rMax << endl;
    for(int i = lMin; i <= rMax; i++) {
        int iAppearence = freq[i].first;
        int canBeRemoved = freq[i].second;
        //cerr << "element i: " << i << " appears: " << iAppearence << " can remove: " << canBeRemoved << endl;
        if(iAppearence - canBeRemoved >= kAppear) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    FAST;
    MULTI {
        solve();
    }
}

