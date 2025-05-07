/**
 * File              : vpc23_c.cpp
 * Author            : distiled
 * Date              : 02.08.2023
 * Last Modified Date: 04.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

int n, c[MAXN], p[MAXN]; vector<pair<double, vector<int>>> diff; vector<int> res;

signed main() {
    TLE;
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) {
        diff.push_back({c[i] / (double) p[i], {i, c[i], p[i]}});
    }
    sort(all(diff), [&] (pair<double, vector<int>> b, pair<double, vector<int>> c) {
        return b.first > c.first;
    });
    res.push_back(diff[0].second[0]);
    double sum1 = diff[0].second[1], sum2 = diff[0].second[2];
    double curr = diff[0].second[1] / (double) diff[0].second[2];
    for(int i = 1; i < n; i++) {
        sum1 += diff[i].second[1]; sum2 += diff[i].second[2];
        if(curr < (sum1 / (double) sum2)) {
            curr = (sum1 / (double) sum2);
            res.push_back(diff[i].second[0]);
        }
        else {
            break;
        }
    }
    cout << res.size() << endl;
    for(auto i : res) cout << i + 1 << ' ';
}

