/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 09.06.2023
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
//  freopen("ZFACTOR.INP", "r", stdin);
//  freopen("ZFACTOR.OUT", "w", stdout);
  int n, k; cin >> n >> k;
  int a[n];
  map<int, int> f; //luu tan suat xuat hien cua phan tu co tsnt nho nhat 
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  //minPrime[i] la tsnt nho nhat cua i trong khoang [2, k]
  vector<int> minPrime(k + 1, 0);
  //tsnt nho nhat cua cac phan tu chan la 2
  for(int i = 2; i <= k; i+=2) {
    minPrime[i] = 2;
    f[minPrime[i]]++; //luu tan suat xuat hien
  }
  //sang snt de tim ra phan tu co tsnt nho nhat 
  for(int i = 3; i <= k; i+=2) {
    //neu minPrime[i] chua dc dat thi no chinh la i
    if(minPrime[i] == 0) {
      minPrime[i] = i;
      f[minPrime[i]]++; //luu tan suat
      // voi moi~ boi so' cua i ta dat  minprime[j] = i
      for(int j = i * i; j <= k; j+=i) {
        //neu minPrime[j] chua dc dat thi no cung chinh la i
        if(minPrime[j] == 0) {
          minPrime[j] = i;
          f[minPrime[j]]++; //luu tan suat
        }
      }
    }
  }
  //in kq
  for(int i = 0; i < n; i++) {
    cout << f[a[i]] << endl;
  }
  // dpt O(nlogn)
}

