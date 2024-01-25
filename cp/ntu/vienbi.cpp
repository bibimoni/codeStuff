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

bool check = false;


signed main() {
    FAST;
    int A, B, C; cin >> A >> B >> C;
    if(B == C) {
        cout << "YES";
    }
    else if((B - C) % 3 == 0) {
        bool check = false;
        for(int i = 0; i < 1000000; i++) {
            if(A == 0 && B > 0 && C > 0) {
                A += 2;
                B--;
                C--;
            }
            else if(B > C && C >= 0 && A > 0) {
                B--;
                C += 2;
                A--;
            }
            else if(C > B && B >= 0 && A > 0) {
                C--;
                B += 2;
                A--;
            }
            if(B == C) {
                cout << "YES";
                check = true;
                break;
            }
        }
        if(!check) cout << "NO";
    }
    else {
        cout << "NO";
    }
}

