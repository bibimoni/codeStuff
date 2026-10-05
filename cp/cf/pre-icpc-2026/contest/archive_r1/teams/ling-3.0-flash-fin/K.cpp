#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,k; scanf("%d%d",&n,&k);
        vector<long long> a(n);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        if(k==1){
            long long mn=a[0];
            for(int i=1;i<n;i++) mn=min(mn,a[i]);
            printf("%lld\n",mn);
        } else {
            vector<long long> pref_min(n);
            pref_min[0]=a[0];
            for(int i=1;i<n;i++) pref_min[i]=min(pref_min[i-1],a[i]);
            long long ans=LLONG_MAX;
            for(int r=k;r<=n;r++){
                ans=min(ans, pref_min[r-k] + a[r-1]);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
