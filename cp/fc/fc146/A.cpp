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

int sum = 0;
int k = 0;
vector<int> a;
void extract(int n) {
    while(n != 0) {
        sum += n % 10;
        a.emplace_back(n % 10);
        k++;
        n /= 10;
        dbg(a[k-1]);
    }
}

int res;

void Try(int curr, int i, int step) {
    dbg(curr, step);
    if(curr % 3 == 0) {
        res = min(res, step);
        return;
    }
    if(i == k) {
        if(curr % 3 == 0) {
            res = min(res, step);
        }
        return;
    }
    Try(curr - a[i], i + 1, step + 1);
    Try(curr, i + 1, step);
}

signed main() {
    FAST;
    int n; cin >> n;
    extract(n);
    sort(a.begin(), a.end());
    res = k;
    Try(sum, 0, 0);
    cout << res;
    /*
    int cnt = 0;
    bool flag = false;
    if(sum % 3 == 0) {
        cout << 0;
        flag = true;
    } 
    else if(sum % 3 == 0 && k == 1) {
        cout << k;
        flag = true;
    }
    for(int i = 0; i < k; i++) {
        dbg((sum - a[i]) % 3);
        if((sum - a[i]) % 3 == 0) {
            cout << 1;
            flag = true;
            dbg(sum - a[i]);
            break;
        }
    }
    if(!flag && k == 2) {
        cout << k;
    }
    else if(!flag) {
        cout << 2;
    }
    */
}

