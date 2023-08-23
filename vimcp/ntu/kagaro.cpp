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

int same(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = same(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

signed main() {
    FAST;
    int n, a, b; cin >> n >> a >> b;
    int x0, y0;
    int g = same(a, b, x0, y0);
    if(n % g != 0) {
        cout << -1 << endl;
    }
    else {
        x0 = x0 * n / g;
        y0 = y0 * n / g;
        int res = 1e9; bool flag = false;
        if(x0 >= 0 && y0 >= 0) {
            flag = true;
            res = min(res, x0 + y0);
        }
        bool firstTime = false;
        int firstK = -x0 / (b/g);
        for(int k = firstK; k <= firstK + 3000; k++) {
            int x = x0 + k*(b/g);
            int y = y0 - k*(a/g);
            dbg(x, y);
            if(x < 0 || y < 0) continue;;
            //    if(firstTime) break;
            //}
            //firstTime = true;
            res = min(res, x + y);
            flag = true;
        }
        if(!flag) {
            cout << -1 << endl;
        }
        else {
            cout << res << endl;
        }
    }
}

