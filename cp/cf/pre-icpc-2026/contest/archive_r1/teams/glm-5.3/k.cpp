#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n, k; scanf("%d %d",&n,&k);
        vector<ll> a(n+2);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        vector<ll> pmin(n+2, LLONG_MAX), smin(n+2, LLONG_MAX), v(n+2);
        for(int i=1;i<=n;i++) pmin[i] = min(pmin[i-1], a[i]);
        for(int i=n;i>=1;i--) smin[i] = min(smin[i+1], a[i]);
        for(int i=1;i<=n;i++){
            ll b = LLONG_MAX;
            if(i>1 && i<n) b = max(pmin[i-1], smin[i+1]);
            v[i] = min(a[i], b);
        }
        ll ans = LLONG_MAX;
        if(k==1){ for(int i=1;i<=n;i++) ans=min(ans,v[i]); }
        else {
            vector<ll> pm(n+2, LLONG_MAX);
            for(int i=1;i<=n;i++) pm[i]=min(pm[i-1], v[i]);
            for(int q=k;q<=n;q++) ans = min(ans, v[q] + pm[q-k+1]);
        }
        printf("%lld\n", ans);
    }
}
