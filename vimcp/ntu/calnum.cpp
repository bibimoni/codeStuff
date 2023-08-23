/**
 * File              : calnum.cpp
 * Author            : distiled
 * Date              : 06.05.2023
 * Last Modified Date: 06.05.2023
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
#define MAXN 2000
int nxt() {int n; cin >> n; return n;}
vector<bool> isPrime(MAXN, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < MAXN; i++) {
        if(isPrime[i])
        for(int j = i * i; j < MAXN; j += i) {
            isPrime[j] = false;
        }
    }
}

bool check(int num) {
    int sum1 = 0, sum2 = 0;
    while(num != 0) {
        sum1 += (num % 10) * (num % 10);
        sum2 += (num % 10);
        num /= 10;
    }
    return isPrime[sum1] && isPrime[sum2];
}

signed main() {
    FAST;
    sieve();
    MULTI { 
        int L, R; cin >> L >> R;
        int cnt = 0;
        for(int i = L; i <= R; i++) {
            if(check(i)) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}

