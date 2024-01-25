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
    int m, k; cin >> m >> k;
    int a[m + 1][m + 1];
    for(int i = 0; i <= m; i++) a[i][0] = 0;
    for(int i = 0; i <= m; i++) a[0][i] = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            a[i][j] = nxt();
        }
    }
    if(1 + k * 2 > m) {
        cout << -1 << endl;
    }
    int x = k + 1, y = k + 1;
    int sum = 0;
    //precompute the cost
    int temp = 1, adder = 1;
    for(int i = y - k; i <= y + k; i++) {
        for(int j = x - (temp - 1); j <= x + (temp - 1); j++) {
             cout << a[i][j - 1] << ' ';
             sum += a[i][j - 1];
        }
        if(temp >= k + 1) adder = -adder;
        cout << endl;
        temp += adder;
    }
    dbg(sum);
    temp = 1, adder = 1;
    for(int i = k + 1; i <= m - k; i++) {
        for(int j = k + 1; j <= m - k; j++) {
            for(int g =)            
        }
    }
}

