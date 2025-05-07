/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 10.05.2023
 * Last Modified Date: 10.05.2023
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
#define N (int) 1e5 + 5
#define LG 17
int a[N], st[LG + 1][N];
void preprocess(int n, vector<int> a) {
    for (int i = 0; i < n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int queryMax(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}
int nxt() {int n; cin >> n; return n;}

signed main() {
    FAST;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    map<int, int> f;
    vector<int> diff(n - 1);
    for(int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
        f[diff[i]]++;
    }
    preprocess(n - 1, diff);
    if(m >= n) {
        int remaining = m - n;
        while(remaining--) {
            auto itr = f.rbegin();
            int curr = itr->first; int freq = itr->second;
            if(freq == 1) {
                f.erase(curr);
            }
            else f[curr]--;
            f[floor(curr/2.0)]++;
            f[ceil(curr/2.0)]++;
        }
        cout << f.rbegin() -> first;
    }
    if(n > m) {
        int range = m - 1; //the element in the diff array is n - 1
        int res = 1e9;
        for(int i = 0; i < n - range - 1; i++) {
            res = min(res, queryMax(i, i + range - 1));
            dbg(queryMax(i, i + range - 1));
        }
        cout << res;
    }
}


