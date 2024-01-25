/**
 * File              : disc3.cpp
 * Author            : distiled
 * Date              : 23.05.2023
 * Last Modified Date: 23.05.2023
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
#define maxn (int) 1e5 + 1
int nxt() {int n; cin >> n; return n;}

int a[maxn], t[maxn] = {0}, n, m;
int bound;

int getBIT(int m) {
    int res = 0, idx = m;
    while(idx > 0) {
        res += t[idx];
        idx -= (idx & (-idx));
    }
    return res;
}

void updateBIT(int m, int val) {
    int idx = m;
    while(idx <= bound) {
        t[idx] += val;
        idx += (idx & (-idx));
    }
}

signed main() {
    FAST;
    cin >> n >> m;
    map<int, int> idx;
    int A = n + 1;
    for(int i = 1; i <= n; i++) {
        idx[n + 1 - i] = i;
        t[i] = 0;
    }
    bound = n + m;
    for(int i = 1; i <= m; i++) {
        int x; cin >> x;
        int p = getBIT(idx[x] - 1);
        int q = getBIT(A);
        updateBIT(idx[x], 1);
        cout << A - idx[x] - 1 - (q - p) << ' ';
        idx[x] = A;
        A++;
    }
}


