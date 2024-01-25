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
int r, l;

int g(int x) {
    return (r * r + r - x * x - x) / 2;
}

int f(int x) {
    return (x * x + x - l * l - l) / 2;
}

int h(int x) {
    return abs(f(x) - g(x));
}

signed main() {
    FAST;
    cin >> l >> r;
    int A = r * r + r + l * l + l;
    double ans1 = (3 - (double) sqrt(9 + 8.0 * A)) / (-4.0);
    double ans2 = (3 + (double) sqrt(9 + 8.0 * A)) / (-4.0);
    dbg(ans1, ans2);
    dbg(f(-6), g(-6));
    int res1, res2;
    if(ans1 >= l && ans1 < r) {
        res1 = h(floor(ans1));
        res2 = ceil(ans1) >= r ? 1e9 : h(ceil(ans1));
        dbg(floor(ans1), res1, ceil(ans1), res2);
        if(res1 < res2 || ceil(ans1) >= r) {
            cout << floor(ans1) << endl;
            dbg(f(floor(ans1)), g(floor(ans1)));
        }
        else {
            dbg(f(ceil(ans1)), g(ceil(ans1)));
            cout << ceil(ans1) << endl;
        }
    }
    else if(ans2 >= l && ans2 < r) {
        res1 = h(floor(ans2));
        res2 = ceil(ans2) >= r ? 1e9 : h(ceil(ans2));
 //       dbg(res1, res2);
        if(res1 < res2 || ceil(ans2) >= r) {
            cout << floor(ans2) << endl;
            dbg(f(floor(ans2)), g(floor(ans2)));
        }
        else {
            dbg(f(ceil(ans2)), g(ceil(ans2)));
            cout << ceil(ans2) << endl;
        }
    }
}

