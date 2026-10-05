#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,k; scanf("%d %d",&n,&k);
        vector<ll> a(n);
        for(auto&x:a) scanf("%lld",&x);
        if(k == 1){
            ll ans = a[0];
            for(ll x:a) ans = min(ans, x);
            printf("%lld\n", ans);
            continue;
        }
        ll ans = LLONG_MAX;
        ll best = a[0];
        // best = min a[1..r-k+1]; for r >= k-1 (0-indexed r >= k-1)
        for(int r=k-1;r<n;r++){
            best = min(best, a[r-k+1]);
            ans = min(ans, a[r] + best);
        }
        printf("%lld\n", ans);
    }
}
