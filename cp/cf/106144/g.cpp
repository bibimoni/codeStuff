#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<long long, long long>

const ll INF = 2e18;
const ll N = 3e5 + 5;

ll n;

void solve() {
    string s; cin >> s;
    ll n = s.size();

    vector<ll> cnt(26, 0);

    ll res = 0;
    
    for (ll i = 0; i < n;) {
        ll r = i;
        while (r < n - 1 && s[r + 1] == s[r]) r++;

        int c = s[i] - 'a';

        res += (cnt[c]) * (r - i + 1);
        cnt[c] += r - i + 1;
        res += r - i + 1;

        i = r + 1;

        // cerr << cnt[c] << " " << res << endl;
    }

    bool all = true;
    for (int c = 0; c < 26; c++) {
        all &= cnt[c] > 0;
    }
    res += !all;

    cout << res << endl;
}

int main() {
    // if (fopen("main.inp", "r")) freopen("main.inp", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
