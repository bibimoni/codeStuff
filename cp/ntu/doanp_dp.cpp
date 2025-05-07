/**
 * File              : doanp_dp.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 15.06.2023
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

#define all(x) x.begin(), x.end()
#define int long long
#define mod 1000000007
#define endl '\n'
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
  int n, a, b;
    cin >> n >> a >> b;

    // Khởi tạo danh sách kề
    vector<vector<int>> adj_list(b + 1);
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;
        if (d >= a) {  
            adj_list[s].push_back(d);
        }
    }

    vector<int> dp(b + 1, INT_MAX);
    dp[a] = 0;

    for (int i = a + 1; i <= b; i++) {
        for (int j : adj_list[i]) {  
          if (dp[i] > dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] == INT_MAX) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<pair<int, int>> ans;
    int j = b;
    while (j > a) {
        for (int i : adj_list[j]) {
            if (dp[j] == dp[i] + 1) {
                ans.push_back(make_pair(i, j));
                j = i;
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    if (dp[b] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[b] << endl;
        for (auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}

