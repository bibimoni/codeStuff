#include<bits/stdc++.h> 
using namespace std;
#define int long long
 
void solve(){
    int h,n;
    cin >> h >> n;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    int l=1, r=2e10;
    while(l<r){
        int mid = (l+r)/2; int sum = 0;
        for(int i=1;i<=n;i++){
            sum += ((mid-1)/b[i]+1)*a[i];
        }
        if(sum>=h){
            r = mid;
        }
        else l = mid + 1;
    }
    cout << l;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
