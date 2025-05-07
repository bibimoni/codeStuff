/**
 * https://ntucoder.net/Problem/Details/5643
 * File              : queue.cpp
 * Author            : distiled
 * Date              : 05.05.2023
 * Last Modified Date: 05.05.2023
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

int n; vector<int> a;

int partition(vector<int> &a, int start, int end) {
    int pivot = a[start];
    int count = 0;
    for(int i = start + 1; i <= end; i++) {
        if(a[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(a[pivotIndex], a[start]);
    if(pivotIndex != start)
    cout << pivotIndex + 1 << ' ' << start + 1 << endl;
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex) {
        while(a[i] <= pivot) {
            i++;
        }
        while(a[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex && i != j) {
            swap(a[i], a[j]);
            cout << i + 1 << ' ' << j + 1 << endl;
            i++; j--;
        }
    }
    return pivotIndex;
}

void quickSort(vector<int> &a, int start,int end) {
    if(start >= end) return;
    int p = partition(a, start, end);
    quickSort(a, start, p - 1);
    quickSort(a, p + 1, end);
}

signed main() {
    FAST;
    cin >> n;
    for(int i = 0; i < n; i++) a.push_back(nxt());
    quickSort(a, 0, n - 1);
//    for(int i = 0; i < n; i++) cout << a[i] << ' ';
}

