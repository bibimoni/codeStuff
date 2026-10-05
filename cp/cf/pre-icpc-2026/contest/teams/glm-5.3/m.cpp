#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
typedef unsigned __int128 u128;
const u64 CAP = 2000000000000000000ULL;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        long long n,m; unsigned long long k;
        scanf("%lld %lld %llu",&n,&m,&k);
        if(m > n*(n-1)/2){ printf("-1\n"); continue; }
        vector<vector<u64>> f(n+1);
        f[0].assign(1,1);
        for(int i=1;i<=n;i++){
            long long maxj = min(m, (long long)i*(i-1)/2);
            f[i].assign(maxj+1, 0);
            u128 s = 0;
            for(long long j=0;j<=maxj;j++){
                if(j==0) s = 0;
                else {
                    // window grows: add f[i-1][j-1] -- wait build below
                }
            }
            // sliding window: s = sum_{t=0..i-1} f[i-1][j-t]
            s = 0;
            for(long long j=0;j<=maxj;j++){
                if(j < (long long)f[i-1].size()) s += f[i-1][j];
                if(j >= i && j-i < (long long)f[i-1].size()) s -= f[i-1][j-i];
                f[i][j] = (u64)min<u128>((u128)CAP, s);
            }
        }
        u64 total = (m < (long long)f[n].size()) ? f[n][m] : 0;
        if(k > total){ printf("-1\n"); continue; }
        vector<int> vals; vals.reserve(n);
        for(int i=1;i<=n;i++) vals.push_back(i);
        long long curm=m; u64 kk=k;
        for(int rem=n; rem>=1; rem--){
            long long mx = min(curm, (long long)rem-1);
            for(long long ti=0; ti<=mx; ti++){
                long long j=curm-ti;
                u64 cnt = (j>=0 && j<(long long)f[rem-1].size()) ? f[rem-1][j] : 0;
                if(kk<=cnt){ printf("%d ", vals[ti]); vals.erase(vals.begin()+ti); curm=j; break; }
                kk-=cnt;
            }
        }
        printf("\n");
    }
    return 0;
}
