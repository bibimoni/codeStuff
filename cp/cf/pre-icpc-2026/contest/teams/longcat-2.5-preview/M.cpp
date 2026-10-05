#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; ll m, k;
        scanf("%d %lld %lld",&n,&m,&k);
        int maxm = n*(n-1)/2;
        if(m > maxm){ printf("-1\n"); continue; }
        vector<vector<ll>> dp(n+1, vector<ll>(maxm+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            __int128 run = 0;
            for(int j=0;j<=maxm;j++){
                run += dp[i-1][j];
                if(j >= i) run -= dp[i-1][j-i];
                dp[i][j] = (ll)min((__int128)k, run);
            }
        }
        if(k > dp[n][m]){ printf("-1\n"); continue; }
        vector<int> rem(n);
        iota(rem.begin(), rem.end(), 1);
        ll remm = m;
        vector<int> ans;
        for(int pos=0;pos<n;pos++){
            for(int idx=0; idx<(int)rem.size(); idx++){
                int c = idx;
                if(remm - c < 0) continue;
                ll ways = dp[n-pos-1][remm - c];
                if(k <= ways){
                    ans.push_back(rem[idx]);
                    remm -= c;
                    rem.erase(rem.begin() + idx);
                    break;
                } else {
                    k -= ways;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
