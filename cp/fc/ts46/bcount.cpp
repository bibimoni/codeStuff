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
    int N, Q; cin >> N >> Q;
    int a[N + 1]; a[0] = 0;
    int pre1[N+1] = {0}; 
    int pre2[N+2] = {0}; 
    int pre3[N+3] = {0};
    for(int i = 1; i <= N; i++) {
        a[i] = nxt();
        pre1[i] = pre1[i - 1] + (int) (a[i] == 1);
        pre2[i] = pre2[i - 1] + (int) (a[i] == 2);
        pre3[i] = pre3[i - 1] + (int) (a[i] == 3);
    }
    while(Q--) {
        int l, r; cin >> l >> r;
        int t1 = - pre1[l - 1] + pre1[r];
        int t2 = - pre2[l - 1] + pre2[r];
        int t3 = - pre3[l - 1] + pre3[r];
        cout << t1 << ' ' << t2 << ' ' << t3 << endl;
    }

    
}

