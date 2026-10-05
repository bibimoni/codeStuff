#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll pw(ll b,ll e){ ll r=1; b%=MOD; while(e){ if(e&1) r=r*b%MOD; b=b*b%MOD; e>>=1; } return r; }
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> a(n+1);
        unordered_map<ll,vector<int>> occ;
        occ.reserve(n*2+16);
        ll S=0;
        for(int i=1;i<=n;i++){ scanf("%lld",&a[i]); S+=a[i]; if(i<n) occ[S].push_back(i); }
        if(S==0){
            int z=occ.count(0)?(int)occ[0].size():0;
            printf("%lld\n",pw(2,z));
            continue;
        }
        ll ans=1; // k=1 whole necklace
        // candidates: interior prefix values v dividing S
        // copy keys to vector to avoid rehash issues
        vector<ll> cand; cand.reserve(occ.size());
        for(auto&kv:occ){ ll v=kv.first; if(v && S%v==0){ ll k=S/v; if(k>=2 && k-1<=n-1) cand.push_back(v); } }
        // per candidate T=v: count tuples
        // f layers
        vector<ll> fprev, fcur;
        for(ll T:cand){
            ll k=S/T;
            bool ok=true;
            // j=1 special: f[i]=1
            auto it1=occ.find(T);
            if(it1==occ.end()) continue; // can't happen (T in cand from occ)
            fcur.assign(it1->second.size(),1);
            for(ll j=2;j<=k-1;j++){
                auto it=occ.find(j*T);
                if(it==occ.end()){ ok=false; break; }
                const vector<int>& pv=it1->second; // positions of (j-1)T? careful
                (void)pv;
                fprev.swap(fcur);
                const vector<int>& nextPos=it->second;
                // previous positions: value (j-1)*T
                auto itp=occ.find((j-1)*T);
                const vector<int>& prevPos=itp->second;
                fcur.assign(nextPos.size(),0);
                // two pointers
                int pi=0, pn=prevPos.size();
                ll run=0;
                for(int i=0;i<(int)nextPos.size();i++){
                    while(pi<pn && prevPos[pi]<nextPos[i]){ run=(run+fprev[pi])%MOD; pi++; }
                    fcur[i]=run;
                }
            }
            if(!ok) continue;
            ll tot=0; for(ll x:fcur){ tot=(tot+x)%MOD; }
            ans=(ans+tot)%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
