#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        long long n,m; unsigned long long k;
        scanf("%lld %lld %llu",&n,&m,&k);
        vector<int> p(n); for(int i=0;i<n;i++) p[i]=i+1;
        unsigned long long cnt=0; bool found=false;
        do{
            int inv=0;
            for(int i=0;i<n;i++)for(int j=i+1;j<n;j++) if(p[i]>p[j]) inv++;
            if(inv==m){ cnt++; if(cnt==k){ for(int i=0;i<n;i++) printf("%d ",p[i]); printf("\n"); found=true; break; } }
        } while(next_permutation(p.begin(),p.end()));
        if(!found) printf("-1\n");
    }
}
