#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
static const ll CAP = (ll)4e18;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        ll n, m, k;
        scanf("%lld %lld %lld",&n,&m,&k);
        vector<vector<ll>> cnt(n+1, vector<ll>(m+1, 0));
        cnt[0][0]=1;
        for(ll i=1;i<=n;i++){
            lll acc=0;
            for(ll j=0;j<=m;j++){
                acc += cnt[i-1][j];
                if(j >= i) acc -= cnt[i-1][j-i];
                cnt[i][j] = acc > (lll)CAP ? CAP : (ll)acc;
            }
        }
        if(k > cnt[n][m]){ printf("-1\n"); continue; }
        vector<ll> rem(n); for(ll i=0;i<n;i++) rem[i]=i+1;
        ll inv=m, len=n;
        vector<ll> ans;
        bool ok=true;
        for(ll pos=0; pos<n; pos++){
            bool picked=false;
            ll lim = min(len-1, inv);
            for(ll r=0;r<=lim;r++){
                ll c = cnt[len-1][inv-r];
                if(k > c) k -= c;
                else {
                    ans.push_back(rem[r]);
                    rem.erase(rem.begin()+r);
                    inv -= r;
                    picked=true;
                    break;
                }
            }
            if(!picked){ ok=false; break; }
            len--;
        }
        if(!ok){ printf("-1\n"); continue; }
        for(ll i=0;i<n;i++) printf("%lld%c", ans[i], i==n-1?'\n':' ');
    }
}
