#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<array<int,3>> e(n-1);
    for(auto&a:e) scanf("%d %d %d",&a[0],&a[1],&a[2]);
    vector<int> p(n); iota(p.begin(),p.end(),1);
    long long ans=0;
    do{
        vector<int> pos(n+1);
        for(int i=0;i<n;i++) pos[p[i]]=i;
        bool ok=true;
        for(auto&a:e){
            int u=a[0],v=a[1],w=a[2];
            if(w==0) continue;
            if(w==1 && pos[u]>pos[v]) ok=false;
            if(w==2 && pos[v]>pos[u]) ok=false;
        }
        if(ok) ans++;
    }while(next_permutation(p.begin(),p.end()));
    printf("%lld\n", ans%998244353);
    return 0;
}
