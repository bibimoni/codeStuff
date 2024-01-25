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
    int n; cin >> n;
    int A[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> res(n, vector<int> (n, 0));
    for(int curr = 0; curr < n; curr++) {
        int currPlaceRow = n - 1;
        for(int i = n - 1; i >= 1; i--) {
            if(!A[i][curr]) continue;
            for(int j = i - 1; j >= 0; j--) {
                if(A[j][curr] != 0 && A[i][curr] != A[j][curr]) break;
                if(A[i][curr] == A[j][curr]) {
                    A[i][curr] = A[i][curr] * 2;
                    dbg('a');
                    A[j][curr] = 0;
                    break;
                }
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            res[currPlaceRow][curr] = A[i][curr];
            if(A[i][curr] != 0) currPlaceRow--;
            A[i][curr] = 0;    
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}

