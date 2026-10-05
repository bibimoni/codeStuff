#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll MOD = 1000000007LL;

static ll pw2(int e){
    ll r=1,b=2;
    while(e){ if(e&1) r=r*b%MOD; b=b*b%MOD; e>>=1; }
    return r;
}

int main(){
    int t;
    if(scanf("%d",&t)!=1) return 0;
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> p(n+1,0);
        for(int i=1;i<=n;i++){ ll x; scanf("%lld",&x); p[i]=p[i-1]+x; }
        ll S=p[n];
        if(S==0){
            int m=0;
            for(int i=1;i<n;i++) if(p[i]==0) m++;
            printf("%lld\n", pw2(m));
            continue;
        }
        if(S<0){ S=-S; for(auto&x:p) x=-x; }
        unordered_map<ll, vector<int>> pos;
        pos.reserve(n*2+4);
        for(int i=1;i<n;i++) if(p[i]>0) pos[p[i]].push_back(i);
        ll ans=1;
        vector<ll> f;
        vector<int> active;
        for(auto&kv:pos){
            ll v=kv.first;
            if(v>=S) continue;
            if(S%v) continue;
            ll k=S/v;
            if(k>(ll)n) continue;
            active.clear();
            ll q=1;
            for(;q<k;q++){
                auto it=pos.find(q*v);
                if(it==pos.end()) break;
                for(int idx:it->second) active.push_back(idx);
            }
            if(q<k) continue;
            sort(active.begin(), active.end());
            f.assign(k,0); f[0]=1;
            for(int idx:active){
                ll qq=p[idx]/v;
                f[qq]=(f[qq]+f[qq-1])%MOD;
            }
            ans=(ans+f[k-1])%MOD;
        }
        printf("%lld\n",ans);
    }
}
