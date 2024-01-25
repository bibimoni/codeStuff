/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 07.05.2023
 * Last Modified Date: 08.05.2023
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
#define MAXN (3e7 + 1)

vector<int> isPrime(MAXN, true);
vector<int> primes;
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < MAXN; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i < MAXN; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int sqr(int x) {
    return x * x;
}
int nxt() {int n; cin >> n; return n;}
signed main() {
    FAST;
    sieve();
    MULTI {
        int n = nxt();
        if(n < 1e16) {
        int k = 2;
        int temp = n;
        int cnt = 0;
        while(n != 1) {
            if(n % k == 0) {
                n /= k;
                cnt++;
                if(cnt == 2) break;
            }
            else {
                cnt = 0;
                k++;
            }
        }
        cout << k << ' ' << temp / (k * k) << endl;
        }
        else {
for(int i = 0; i < primes.size() && sqr(primes[i]) < n; i++) {
//            dbg(primes[i]);
            if(n % sqr(primes[i]) ==  0 && sqr(primes[i]) != 0) {
                int temp = n / sqr(primes[i]);
//                dbg(temp);
                if(temp >= 2 && temp < MAXN && isPrime[temp]) {
                    cout << primes[i] << ' ' << temp << endl;
                    break;
                }
            }
        }
        }
    }
}

