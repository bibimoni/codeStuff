#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,k; scanf("%d %d",&n,&k);
        vector<ll> a(n);
        for(auto&x:a) scanf("%lld",&x);
        if(k==1){ printf("%lld\n", *min_element(a.begin(),a.end())); continue; }
        ll best = LLONG_MAX; // min a[l] for l <= r-(k-1)
        ll ans = LLONG_MAX;
        // r from k-1 .. n-1, l index = r-(k-1) newest included
        for(int r=k-1;r<n;r++){
            best = min(best, a[r-(k-1)]);
            ans = min(ans, best + a[r]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
