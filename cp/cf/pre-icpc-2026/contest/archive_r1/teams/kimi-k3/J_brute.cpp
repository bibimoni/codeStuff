#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> a(n);
        for(auto&x:a) scanf("%lld",&x);
        if(n==1){ printf("1\n"); continue; }
        ll ans=0;
        for(int msk=0; msk < (1<<(n-1)); msk++){
            ll cur=0; bool ok=true; ll target=LLONG_MIN;
            vector<ll> segs;
            ll s=0;
            for(int i=0;i<n;i++){
                s+=a[i];
                if(i==n-1 || (msk>>i)&1){ segs.push_back(s); s=0; }
            }
            for(size_t i=1;i<segs.size();i++) if(segs[i]!=segs[0]){ ok=false; break; }
            (void)target; (void)cur;
            if(ok) ans++;
        }
        printf("%lld\n", ans%MOD);
    }
    return 0;
}
