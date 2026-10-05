#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

ll modpow(ll a, ll e){ ll r=1; while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1; } return r; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<ll> P(n+1,0);
        for(int i=1;i<=n;i++){ ll a; cin>>a; P[i]=P[i-1]+a; }
        ll S=P[n];
        if(S==0){
            int z=0; for(int i=1;i<n;i++) if(P[i]==0) z++;
            cout<<modpow(2,z)<<'\n';
            continue;
        }
        unordered_map<ll, vector<int>> mp;
        mp.reserve(2*n+1);
        for(int i=1;i<n;i++) mp[P[i]].push_back(i);
        ll ans=1; // single strand
        for(int k=2;k<=n;k++){
            if(S % k != 0) continue;
            ll c = S/k;
            vector<pair<int,int>> all;
            all.reserve(k);
            bool ok=true;
            for(int j=1;j<k;j++){
                auto it=mp.find(j*c);
                if(it==mp.end()){ ok=false; break; }
                for(int pos: it->second) all.push_back({pos,j});
            }
            if(!ok) continue;
            sort(all.begin(),all.end());
            vector<ll> dp(k,0);
            dp[0]=1;
            for(auto& pr: all){
                dp[pr.second] += dp[pr.second-1];
                if(dp[pr.second]>=MOD) dp[pr.second]-=MOD;
            }
            ans += dp[k-1];
            if(ans>=MOD) ans-=MOD;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
