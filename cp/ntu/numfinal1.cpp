/**
 * https://ntucoder.net/Problem/Details/5529
 * File              : numfinal1.cpp
 * Author            : distiled
 * Date              : 12.05.2023
 * Last Modified Date: 12.05.2023
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
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

int modulo(int a, string b) {
    int mod = 0;
    for(int i = 0; i < b.size(); i++) {
        mod = (mod * 10 + (b[i] - '0')) % a;
    }
    return mod;
}

signed main() {
    FAST;
    string x, y; cin >> x >> y;
    vector<int> a;
    a.push_back(x[0] - '0');
    int sA = x.size(), sB = y.size();
    if(sA == 1 && sB == 1 && a[0] == 0 && y[0] == '0') cout << 1;
    else if(sB == 1 && y[0] == '0') cout << 1;
    else if(sA == 1 && a[0] == 0) cout << 0;
    else {
        a.push_back(x[sA - 1] - '0');
        int temp = modulo(4, y);
        int exp = (temp == 0) ? 4 : temp;
        int res = pow(a[a.size() - 1], exp);
        cout << res % 10;
    }
}

