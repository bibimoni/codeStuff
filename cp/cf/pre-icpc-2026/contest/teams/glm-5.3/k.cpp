#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,k; scanf("%d %d",&n,&k);
        vector<long long> a(n);
        for(auto &x:a) scanf("%lld",&x);
        if(k==1){
            long long m=a[0]; for(auto x:a) m=min(m,x);
            printf("%lld\n", m); continue;
        }
        vector<long long> suf(n+1, LLONG_MAX);
        for(int i=n-1;i>=0;i--) suf[i]=min(a[i], suf[i+1]);
        long long ans=LLONG_MAX;
        for(int i=0;i+k-1<n;i++) ans=min(ans, a[i]+suf[i+k-1]);
        printf("%lld\n", ans);
    }
    return 0;
}
