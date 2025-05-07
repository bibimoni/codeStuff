/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 13.05.2023
 * Last Modified Date: 14.05.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

signed main() {
    FAST;
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    int a[n], pre[n];
    cin >> a[0];
    pre[0] = a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int ans = 0, changes = 0;
    vector<int> costs;
    bool check = true;
    for(int i = 0; i < n; i++) {
        dbg(i);
        if(s[i] != t[i])  {
            ans += a[i];
            dbg(ans, a[i], i);
            if(check) {
                changes++;
                check = false;
            }
        }
        else {
            int curr = 0;
            check = true;
            while(s[i] == t[i]) {
                curr += a[i];
                i++;
            }
            i--;
            costs.push_back(curr);
        }
    }
    dbg(ans);
    sort(costs.begin(), costs.end(), greater<int>());
    while(changes > k) {
        ans+= costs.back();
        costs.pop_back();
        changes--;
    }
    cout << ans;
}

