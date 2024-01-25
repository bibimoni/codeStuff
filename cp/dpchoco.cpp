/**
 * File              : dpchoco.cpp
 * Author            : distiled
 * Date              : 08.05.2023
 * Last Modified Date: 08.05.2023
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
    MULTI {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int target = *max_element(a, a + n);
        int value[3] = {1, 2, 5};
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> dp(target + 1, 1e6);
            dp[a[i]] = 0;
            dbg(a[i]);
            for(int j = a[i]; j <= target; j++) {
                for(int k = 0; k < 3; k++) {
                    dbg(j, a[i], value[k]);
                    if(j >= a[i] + value[k]) {
                        dp[j] = min(dp[j], dp[j - value[k]] + 1);
                    }
                }
            }
            dbg(dp[target]);
            ans += dp[target];
        }
        cout << ans << endl;
    }
}

