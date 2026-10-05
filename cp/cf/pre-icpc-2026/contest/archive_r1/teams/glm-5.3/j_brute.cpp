#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll MOD = 1000000007LL;

int main(){
    int t;
    if(scanf("%d",&t)!=1) return 0;
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> a(n);
        for(auto&v:a) scanf("%lld",&v);
        ll ans=0;
        for(int mask=0;mask<(1<<(n-1));mask++){
            // cuts where bit i set = cut after position i+1 (i in 0..n-2)
            vector<ll> sums;
            ll cur=0;
            for(int i=0;i<n;i++){
                cur+=a[i];
                if(i<n-1 && (mask>>i)&1){ sums.push_back(cur); cur=0; }
            }
            sums.push_back(cur);
            bool ok=true;
            for(int i=1;i<(int)sums.size();i++) if(sums[i]!=sums[0]) ok=false;
            if(ok) ans++;
        }
        printf("%lld\n", ans%MOD);
    }
}
