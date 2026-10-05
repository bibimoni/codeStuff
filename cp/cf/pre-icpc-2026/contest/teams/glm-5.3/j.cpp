#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<long long> P(n+1,0);
        for(int i=1;i<=n;i++){ long long x; scanf("%lld",&x); P[i]=P[i-1]+x; }
        long long S=P[n];
        long long ans;
        if(S==0){
            long long z=0;
            for(int i=1;i<n;i++) if(P[i]==0) z++;
            long long pw=1; for(long long i=0;i<z;i++) pw=pw*2%MOD;
            ans=pw;
        } else {
            ans=1;
            vector<long long> stepTotal; // reused per k
            for(int k=2;k<=n;k++){
                if(S%k!=0) continue;
                long long d=S/k;
                stepTotal.assign(k, 0);
                for(int p=1;p<n;p++){
                    long long v=P[p];
                    if(v==0) continue;
                    if(v%d!=0) continue;
                    long long i=v/d;
                    if(i<1||i>k-1) continue;
                    stepTotal[i] += (i==1)?1:stepTotal[i-1];
                    if(stepTotal[i] >= MOD) stepTotal[i] -= MOD;
                }
                ans=(ans+stepTotal[k-1])%MOD;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
