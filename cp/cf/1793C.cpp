#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

signed main() {
    FAST;
    MULTI {
        int n = nxt();
        int a[n + 1];
        for(int i = 1; i <= n; i++) {
            a[i] = nxt();
        }
        int left = 1, right = n;
        int l = 1, r = n;
        while(l < r) {
            if(a[l] == left) {
                l++; left++;
            }
            else if(a[r] == right) {
                r--; right--;
            }
            else if(a[l] == right) {
                l++; right--;
            }
            else if(a[r] == left) {
                r--; left++;
            }
            else {
                break;
            }
        }
        if(l == r) cout << -1;
        else cout << l << ' ' << r;
        cout << endl;
    }
}

