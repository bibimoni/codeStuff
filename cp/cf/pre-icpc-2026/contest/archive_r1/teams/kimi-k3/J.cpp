#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct H {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(ll x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll pw(ll b, ll e){ ll r=1; while(e){ if(e&1) r=r*b%MOD; b=b*b%MOD; e>>=1;} return r; }

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        if(n==1){ printf("1\n"); continue; }
        vector<ll> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
        ll S = p[n];
        unordered_map<ll, vector<int>, H> pos;
        pos.reserve(n*2);
        ll z=0;
        for(int i=1;i<n;i++){
            if(p[i]==0) z++;
            pos[p[i]].push_back(i);
        }
        if(S==0){
            printf("%lld\n", pw(2,z));
            continue;
        }
        ll ans = 1;
        for(auto& kv : pos){
            ll v = kv.first;
            if(v==0) continue;
            if(S % v) continue;
            ll m = S / v;
            if(m < 2 || m > n) continue;
            vector<int> possprev = kv.second;
            vector<ll> cumprev(possprev.size());
            for(size_t i=0;i<possprev.size();i++) cumprev[i] = (ll)i+1;
            bool dead = false;
            for(ll j=2; j<=m-1; j++){
                auto it = pos.find(j*v);
                if(it==pos.end()){ dead=true; break; }
                vector<int>& L = it->second;
                vector<ll> cum(L.size());
                for(size_t i=0;i<L.size();i++){
                    int idx = lower_bound(possprev.begin(), possprev.end(), L[i]) - possprev.begin();
                    ll c = idx>0 ? cumprev[idx-1] : 0;
                    cum[i] = ((i>0?cum[i-1]:0) + c) % MOD;
                }
                possprev = L;
                cumprev = move(cum);
            }
            if(dead) continue;
            ans += cumprev.back();
            if(ans>=MOD) ans-=MOD;
        }
        printf("%lld\n", ans%MOD);
    }
    return 0;
}
