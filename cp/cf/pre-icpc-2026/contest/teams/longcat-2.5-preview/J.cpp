#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> a(n);
        for(auto&x:a) scanf("%lld",&x);
        vector<ll> pref(n);
        pref[0] = a[0];
        for(int i=1;i<n;i++) pref[i] = pref[i-1] + a[i];
        ll S = pref[n-1];
        ll ans = 0;
        if(S == 0){
            ll z = 0;
            for(int i=0;i<n-1;i++) if(pref[i] == 0) z++;
            ans = 1;
            for(int i=0;i<z;i++) ans = ans * 2 % MOD;
        } else {
            ans = 1;
            for(int k=2;k<=n;k++){
                if(S % k != 0) continue;
                ll T = S / k;
                vector<ll> ways(k, 0);
                ways[0] = 1;
                for(int i=0;i<n-1;i++){
                    ll v = pref[i];
                    if(v % T != 0) continue;
                    ll j = v / T;
                    if(j >= 1 && j <= k-1){
                        ways[j] = (ways[j] + ways[j-1]) % MOD;
                    }
                }
                ans = (ans + ways[k-1]) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
}
