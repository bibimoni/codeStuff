/**
 * File              : A.cpp
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

int nxt() {int n; cin >> n; return n;}
// Function to count the number of factors
int divisorsOfNchooseK(long long N, long long K)
{
    int M = max((int)sqrt(N), K);
    vector<bool> prime(M + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p < prime.size(); p++) {
        if (prime[p]) {
            for (int i = 2 * p; i < prime.size(); i += p) {
                prime[i] = false;
            }
        }
    }
    vector<int> deno(K + 1);
 
    for (int i = 1; i <= K; i++) {
        deno[i] = i;
    }
    vector<int> nume(K);
 
    int offset = N - K + 1;
 
    for (int i = 0; i < K; i++) {
        nume[i] = offset + i;
    }
    int ans = 1;
    for (int p = 2; p < prime.size(); p++) {
        if (prime[p]) {
            int power = 0;
            for (int i = p; i <= K; i += p) {
                while (deno[i] % p == 0) {
                    power--;
                    deno[i] /= p;
                }
            }
            for (int i = ((N - K + 1) + p - 1) / p * p; i <= N; i += p) {
                while (nume[i - offset] % p == 0) {
                    power++;
                    nume[i - offset] /= p;
                }
            }
            ans *= (power + 1);
        }
    }
 
    for (int i = N - K + 1; i <= N; i++) {
        if (nume[i - offset] != 1) {
            ans *= 2;        
        }
    }
 
    return ans;
}
signed main()
{
    int N, K;
    int T = 11000;
    while(T--) {
        cin >> N >> K;
        int ans = divisorsOfNchooseK(N, K);
        cout << ans << endl;
    }
    return 0;
}

