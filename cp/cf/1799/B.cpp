#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)
 
int nxt() {int n; cin >> n; return n;}

bool equals(vector<int> a) {
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] != a[i + 1]) return false;
    }
    return true;
}

signed main() {
    FAST;
    MULTI {
        int n = nxt();
        vector<int> a(n);
        bool check = false;
        bool check1 = true;
        for(int i = 0; i < n; i++) {
            a[i] = nxt();
            if(i > 0 && a[i] != a[i - 1]) check1 = false;
            if(a[i] == 1) check = true;
        }
        if(check1) {
            cout << 0 << endl;
            continue;
        }
        if(check) {
            cout << -1 << endl;
            continue;
        }
        vector<int> res;
        vector<int> prev;
        while(!equals(a)) {
            int minI = 1e9;
            int temp = -1;
            for(int i = 0; i < n; i++) {
                if(a[i] < minI) {
                    minI = a[i];
                    temp = i;
                }
            }
            for(int i = 0; i < n; i++) {
                if(a[i] != minI and a[i] > minI) {
                    int temp1 = ceil(a[i] /(double) minI);
                    res.push_back(i + 1);
                    res.push_back(temp + 1);
                    a[i] = temp1;
                }
            }
            //if the changes doesnt affect the array and its elements arent equal then
            if(a == prev) {
                cout << -1 << endl;
                break;
            }
            prev = a;
        }
        cout << (res.size() >> 1) << endl;
        for(int i = 0; i < res.size(); i += 2) {
            cout << res[i] << ' ' << res[i + 1] << endl;
        }
    }
}
