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
#define MAXN (1e5 + 5)
int nxt() {int n; cin >> n; return n;}

vector<bool> isPrime(MAXN, true);

void sieve() {
    isPrime[0] = 0; isPrime[1] = 0;
    for(int i = 2; i * i < MAXN; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < MAXN; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

bool checkPali(int num) {
    if(num % 10 == 0) return false;
    int temp = 0;
    while(num > temp) {
        temp = temp * 10 + num % 10;
        num /= 10;
    }
//    dbg(temp, num);
    return temp == num || temp / 10 == num;
}

signed main() {
    FAST;
    sieve();
    int cnt = 0; int a, b; cin >> a >> b;
    dbg(checkPali(11111));
    for(int i = a; i <= b; i++) {
//        dbg(i, checkPali(i));
        if(isPrime[i] && checkPali(i)) cnt++; 
    }
    cout << cnt;
}

