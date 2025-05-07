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
#define MAXN (int) 1e6 + 5
int nxt() {int n; cin >> n; return n;}

vector<bool> isPrime(MAXN, true);
vector<bool> product(MAXN, false);
vector<int> primes;
void sieve() {
    isPrime[0] = false; isPrime[1] = false;
    for(int i = 2; i * i <= MAXN; i ++) {
        if(isPrime[i]) {
            primes.emplace_back(i);
            for(int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < primes.size() - 1; i++) {
        for(int j = 0; j < primes.size(); j++) {
            if(primes[i] * primes[j] <= 1e6) {
                product[primes[i] * primes[j]] = true;
                cnt++;
            }
        }
    }
    dbg(cnt);
}

bool isInt(double num) {
    return num == (int) num; 
}
 
signed main() {
    FAST;
    int n, t; cin >> n >> t;
    int a[n];
    bool hasZero = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        hasZero = (a[i] == 0);
    }
    sieve();
    while(t--) {
        int x = nxt();
        if(x == 0 && hasZero) {
            cout << "yes" << endl;
            continue;
        }
        else if(x == 0 && !hasZero){
            cout << "no" << endl;
            continue;
        }
        bool check = false;
        for(int i = 0; i < n; i++) {
            if(check) break;
            for(int powp = 0; pow(a[i], powp) <= 1e6; powp++) {
                if(check) break;
                double remain = x / pow(a[i], powp);
                dbg(a[i], powp, remain, isInt(remain));
                if(!isInt(remain)) continue;
                if(product[(int) remain]) {
                    dbg(a[i], powp);
                    cout << "yes" << endl;
                    check = true;
                }
            }
        }
        if(!check) {
            cout << "no" << endl;
        }
    }
}
