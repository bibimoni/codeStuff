#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<long long, long long>

vector<ll> roirac;

const ll INF = 2e18;
const ll N = 3e5 + 5;

ll n;

string ll2str(ll x) {
    string s = "";
    while (x) {
        s = (char)(x % 10 + '0') + s;
        x /= 10;
    }
    return s;
}

ll str2ll(string s) {
    ll res = 0;
    for (char c : s) {
        res = res * 10 + (c - '0');
    }
    return res;
}

string cyclic(string s) {
    string res = s;
    res = s.back() + res;
    res.pop_back();
    return res;
}

void solve() {
    cin >> n;

    string sn = ll2str(n);
    // cerr << sn << endl;
    vector<string> lsn{sn};
    while (true) {
        string tt = cyclic(lsn.back());
        if (tt != lsn[0]) lsn.push_back(tt);
        else break;
    }

    vector<ll> llsns;
    for (auto s : lsn) {
        llsns.push_back(str2ll(s));
    }

    // for (auto s : llsns) {
    //     cerr << s << endl;
    // }

    ll tlen = lsn[0].size();

    vector<ll> res;

    for (int i = 0; i < llsns.size(); i++) {
        ll nx = llsns[i];
        if (nx < n) continue;

        ll x = nx - n;
        if (x == 0) continue;

        if (x % tlen == i) {
            res.push_back(x);
        }
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    
    cout << res.size() << endl;
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    if (fopen("main.inp", "r")) freopen("main.inp", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
