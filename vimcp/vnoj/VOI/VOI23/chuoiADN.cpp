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
    string s; cin >> s;
    int n = s.length();
    map<int, pair<int, int>> range; // left, cnt, right // right, cnt, left
    int cnt; 
    int j = 0;
    while(s[j] == '?') j++;
    int i = j;
    //find every continuous Nu and stores its length as L, R indices
    for(; i < n; i++) {
        if(s[i] != s[i + 1]) {
            cnt = i - j + 1;
            range[i] = {cnt, j};
            range[j] = {cnt, i};
            cout << j << ' ' << i << ' ' << cnt << endl;
            j = i + 1;
        }
        if(s[i] == '?') {
            while(s[i] == '?') i++;
            j = i;
        }
    }
    cout << endl;
    //using the given range to change ? into the longer length of Nu from 2 sides
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            //number of continuous Nu from both side (l , r)
             int cntLeft = (i - 1 < 0) ? 0 : range[i - 1].first;
             int cntRight = (i + 1 == n) ? 0 : range[i + 1].first;
             cout << i << ' ' << cntLeft << ' ' << cntRight << endl;
             if(cntLeft > cntRight) {
                s[i] = s[i - 1];
                range[i].first = cntLeft + 1;
                range[i].second = range[i - 1].second;
                range[range[i].second].first = cntLeft + 1;
                range[range[i].second].second = i;
             }
             else {
                 s[i] = s[i + 1];
                 range[i].first = cntRight + 1;
                 range[i].second = range[i + 1].second;
                 range[range[i].second].first = cntRight + 1;
                 range[range[i].second].second = i;
             }
        }
    }
    for(auto &nu : s) cout << nu;
    cout << endl;
    int res = n * (n + 1) / 2;
    int removal = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            int size = range[i - 1].first;
            if(size <= 1) continue;
            removal += size * (size + 1) / 2;
        }
    }
    cout << res << endl;
     
}

