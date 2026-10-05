#include <bits/stdc++.h>
using namespace std;
// f[n][m] = #permutations of n elements with exactly m inversions, capped at CAP
const long long CAP=(long long)4e18;
static long long f[301][301*300/2+1];
int main(){
    int N=300, M=300*299/2;
    for(int n=0;n<=N;n++) f[n][0]=1;
    for(int n=1;n<=N;n++){
        // sliding window over m: f[n][m] = sum_{j=0..min(m,n-1)} f[n-1][m-j]
        __int128 wsum=0;
        for(int m=0;m<=M;m++){
            wsum+=f[n-1][m];
            if(m>=n){ wsum-=f[n-1][m-n]; }
            f[n][m]= wsum>CAP ? CAP : (long long)wsum;
        }
    }
    int t; scanf("%d",&t);
    while(t--){
        int n; long long m,k; scanf("%d %lld %lld",&n,&m,&k);
        int maxm=n*(n-1)/2;
        if(m>maxm || k>f[n][m]){ printf("-1\n"); continue; }
        // greedy: choose next element; small pool
        vector<int> pool(n); iota(pool.begin(),pool.end(),1);
        vector<int> ans;
        long long rem=k;
        for(int pos=0;pos<n;pos++){
            int left=n-pos-1;
            // try putting pool[j] (j-th smallest remaining): adds j inversions
            for(int j=0;j<(int)pool.size();j++){
                long long need=m-j;
                if(need<0) break;
                long long cnt = (need<= (long long)left*(left-1)/2) ? f[left][need] : 0;
                if(rem<=cnt){
                    ans.push_back(pool[j]);
                    pool.erase(pool.begin()+j);
                    m=need;
                    break;
                }
                rem-=cnt;
            }
        }
        for(int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
    }
    return 0;
}
