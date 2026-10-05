#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,k; scanf("%d %d",&n,&k);
        vector<long long> a(n+1);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        if(k==1){ printf("%lld\n",*min_element(a.begin()+1,a.end())); continue; }
        // min a_i + a_j, j-i>=k-1 : suffix minimum
        long long ans=LLONG_MAX, suf=LLONG_MAX;
        for(int i=n;i>=1;i--){
            suf=min(suf,a[i]);
            int l=i-(k-1);
            if(l>=1){ /* pair (l,i) handled when iterating left */ }
        }
        // iterate right endpoint j from k..n, track min a_i for i<=j-k+1
        long long pref=LLONG_MAX;
        for(int j=k;j<=n;j++){
            pref=min(pref,a[j-(k-1)]);
            ans=min(ans,pref+a[j]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
