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

bool isPalidrome(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

signed main() {
    FAST;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    map<char, int> f; //map luu tan suat
    int cntOdd, cntEven; //luu so chu~ cai trong substring do dai n - k xuat hien voi tan suat chan lan` / le lan`
    
    //khoi tao gia tri cho cac bien cnt va map
    for(int i = 0; i < n - k; i++) {
        f[s[i]]++;
        //lan dau xuat hien
        if(f[s[i]] == 1) {
            cntOdd++;
        }
        // xuat hien 3, 5, 7, ... lan
        else if(f[s[i]] & 1) {
            cntOdd++;
            cntEven--;
        }
        //xuat hien 2, 4, 6, ... lan
        else if(!(f[s[i]] & 1)) {
            cntOdd--;
            cntEven++;
        }
    }
    bool check = false;
    for(int i = 0; i <= k; i++) {
        //chu cai le xuat hien it hon 2 lan
        dbg(cntOdd, i);
        if(cntOdd <= 1) {
            // kiem tra xau hien tai co phai xau doi xung hay khong
            // [aabc]kde (k = 3, i = 0)
            if(isPalidrome(s.substr(i, n - k))) {
                cout << s.substr(i, n - k);
                check = true;
                break;
            }
        }
        //dat den cuoi, khong cap nhat nua
        if(i == k) break;
        //neu chua co xau doi xung thi di chuyen 
        //neu ki tu tai i xuat hien le lan
        if(f[s[i]] & 1) {
            cntOdd--;
            f[s[i]]--;
            if(f[s[i]] != 0) cntEven++;
        }
        //neu xuat hien chan lan
        else if(!(f[s[i]] & 1)) {
            cntEven--;
            f[s[i]]--;
            cntOdd++;
        }
        //neu ki tu tiep theo i + n - k
        //lan dau xuat hien
        if(f[s[i + n - k]] == 0) {
            cntOdd++;
            f[s[i + n - k]]++;
        }
        //da xuat hien le lan
        else if(f[s[i + n - k]] & 1) {
            cntEven++;
            cntOdd--;
            f[s[i + n - k]]++;
        }
        else if(!(f[s[i + n - k]] & 1)) {
            cntOdd++;
            cntEven--;
            f[s[i + n - k]]++;
        }
    }
    if(!check) {
        cout << "No";
    }
}

