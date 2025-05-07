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
#define MAXN (int) 2e6 + 5
int nxt() {int n; cin >> n; return n;}

vector<int> dp(MAXN, 1e9);

signed main() {
    FAST;
    dp[0] = 0;
    for(int i = 1; i <= MAXN; i++) {
        if(i >= 15) {
            dp[i] = min(dp[i - 15] + 2, dp[i]);
            if(dp[i - 15] + 2 < dp[i]) {
                dp[i - 10] = min(dp[i - 10], dp[i - 15] + 1);
            }
        }
        if(i >= 4) {
            if(i >= 19) {
                dp[i] = min(dp[i - 19] + 3, dp[i]);
                if(dp[i - 19] + 3 < dp[i]) {
                    dp[i - 10] = min(dp[i - 15] + 2, dp[i - 10]);
                    if(dp[i - 15] + 2 < dp[i - 10]) {
                        dp[i - 15] = min(dp[i - 19] + 1, dp[i - 15]);
                    }
                }
            }
            if(i >= 5) {
                dp[i] = min(dp[i - 5] + 2, dp[i]);
                if(dp[i - 5] + 2 < dp[i]) {
                    dp[i - 1] = min(dp[i - 1], dp[i - 5] + 1);
                }
            }
        }
        if(i >= 3) {
            dp[i] = min(dp[i - 3] + 1, dp[i]);
        }
        if(i >= 1) {
            dp[i] = min(dp[i - 1] + 1, dp[i]);
        }
        if(i >= 10) {
            dp[i] = min(dp[i - 10] + 1, dp[i]);
        }
    }
//    for(int i = (int) ( 1e6 - 100); i <= 1e6; i++) {
//        dbg(dp[i]);
//    }
    MULTI {
        cout << dp[nxt()] << endl;
    }
}
