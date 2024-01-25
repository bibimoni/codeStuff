/**
 * File              : writer.cpp
 * Author            : distiled
 * Date              : 04.05.2023
 * Last Modified Date: 04.05.2023
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

signed main() {
    FAST;
    map<int, vector<char>> f;
    f[1] = {'.', ',', '?', '!', '1'};
    f[2] = {'a', 'b', 'c', '2'};
    f[3] = {'d', 'e', 'f', '3'};
    f[4] = {'g', 'h', 'i', '4'};
    f[5] = {'j', 'k', 'l', '5'};
    f[6] = {'m', 'n', 'o', '6'};
    f[7] = {'p', 'q', 'r', 's', '7'};
    f[8] = {'t', 'u', 'v', '8'};
    f[9] = {'w', 'x', 'y', 'z', '9'};
    f[0] = {'_', '0'};
    MULTI {
        string s; cin >> s;
        int currButton = 1, prevButton = 1, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            prevButton = currButton;
            while(true) {
                bool check = false;
                vector<char> currChar = f[currButton];
                for(int j = 0; j < currChar.size(); j++) {
                    if(currChar[j] == s[i]) {
                        ans += j + 1;
                        check = true;
                    }
                }
                if(!check) {
                    currButton = (currButton + 1) % 10;
                }
                else {
                    if(currButton != prevButton) ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}

